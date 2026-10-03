// PBR Shader for Gate of Hell, Copyright (c) 2025 Federation Studio.
// ONCL-C v0.1; full English and Chinese license: mod root LICENSE-PBR.txt.
// Original: https://steamcommunity.com/sharedfiles/filedetails/?id=3548575715
// UFB modification: compress excessive sunlight specular peaks.
// light struct
struct Light
{
    float3 direction;
    float3 color;
    float distanceAttenuation;
    float shadowAttenuation;
};

#define PI (float)3.1415926

// PBR functions
inline float3 fresnelSchlick(float HdV, float3 f0)
{
    //f0 + (1.0 - f0) * pow(clamp(1.0 - HdV, 0.0, 1.0), 5.0)
    float base = clamp((float)1.0 - HdV, (float)0.0, (float)1.0);
    return f0 + ((float)1.0 - f0) * base* base* base* base* base;
}

inline float distributionGGX(float NdH, float roughness)
{
    float a = roughness * roughness;
    float a2 = a * a;

    float num = a2;
    float denom = ((NdH * NdH) * (a2 - (float)1.0) + (float)1.0);
    denom = PI * denom * denom;

    //a2 / denom
    return a2 * rcp(denom);
}

inline float geometrySchlickGGX(float dot, float roughness)
{
    float r = (roughness + (float)1.0);
    float k = (r * r) * (float)0.125;

    return dot * rcp(dot * ((float)1.0 - k) + k);
}

inline float geometrySmith(float NdV, float NdL, float roughness)
{
    float ggx2 = geometrySchlickGGX(NdV, roughness);
    float ggx1 = geometrySchlickGGX(NdL, roughness);

    return ggx1 * ggx2;
}

// direct light
inline float3 directDiffuse(float LdH, float NdL, float NdV, float3 baseColor, float roughness, float3 kD)
{
    float Fd90 = (float)0.5 + (float)2.0 * roughness * LdH * LdH;
    return kD * baseColor * ((float)1.0 / PI) * ((float)1.0 + (Fd90 - (float)1.0) * pow((float)1.0 - NdL, (float)5.0)) * ((float)1.0 + (Fd90 - (float)1.0) * pow((float)1.0 - NdV, (float)5.0));
}

inline float3 directSpecular(float3 F, float NDF, float G)
{
    return F * NDF * G;
}

// UFB: soften only excessive SUN specular radiance before the game's HDR pass.
// One common RGB scale preserves highlight hue; diffuse, GI and local lights
// retain their original response. This is a display-oriented soft shoulder.
inline float3 UFBSoftenSunSpecular(float3 radiance)
{
    float peak = max(radiance.r, max(radiance.g, radiance.b));
    float excess = max(peak - (float)0.5, (float)0.0);
    float limitedPeak = (float)0.5 + excess * rcp((float)1.0 + excess / (float)0.75);
    float scale = min((float)1.0, limitedPeak * rcp(max(peak, (float)0.0001)));
    return radiance * scale;
}

inline float3 directLight(Light light, float3 normal, float3 H,float NdV, float3 F, float3 kD, float3 baseColor, float roughness, float metallic, bool softenSun)
{
    float3 lightDir = light.direction;
    float attenuation = light.distanceAttenuation * light.shadowAttenuation;

    float NdL = saturate(dot(normal, lightDir));
    float NdH = saturate(dot(normal, H));
    float LdH = saturate(dot(lightDir, H));

    float NDF = distributionGGX(NdH, roughness);
    float G = geometrySmith(NdV, NdL, roughness);

    float3 irradiance = PI * light.color * attenuation * NdL;
    float3 diffuseRadiance = directDiffuse(LdH, NdL, NdV, baseColor, roughness, kD) * irradiance;
    float3 specularRadiance = directSpecular(F, NDF, G) * irradiance;
    if (softenSun) specularRadiance = UFBSoftenSunSpecular(specularRadiance);
    return diffuseRadiance + specularRadiance;
}

// indirect light
inline float3 indirectDiffuse(float3 baseColor, float3 gi, float3 kD)
{
    return gi * baseColor * kD;
}

inline float3 indirectSpecular(float NdV, float3 F, float roughness, float3 environment, float3 kD)
{
    float surfaceReduction = 1.0 / (roughness * roughness + 1.0);
    float3 grazingTerm = saturate(1.0 - roughness + (1.0 - kD));
    return surfaceReduction * lerp(F, grazingTerm, pow(1.0 - NdV, 5.0)) * environment;
}

// pbr main
void PBRLighting(
    // basic+GI
    float3 viewDir,
    float3 normal,
    Light mainLight,
    float3 environment,
    float3 gi,
    float3 f0,
    // textures
    float3 baseColor,
    float metallic,
    float roughness,
    float ao,
    out float3 color
)
{
    // textures
    // lerp roughness to 0.1
    roughness = lerp((float)0.1, (float)1.0, roughness);
    f0 = lerp(f0, baseColor, metallic);
    float3 H = normalize(viewDir + mainLight.direction);
    float NdV = saturate(dot(normal, viewDir));
    float HdV = saturate(dot(H, viewDir));
    float3 F = fresnelSchlick(HdV, f0);
    float3 kD = ((float)1.0 - F) * ((float)1.0 - metallic);

    color = (float)0.0;
    // =====main light=====
    float3 direct = directLight(mainLight, normal, H, NdV, F, kD, baseColor, roughness, metallic, true);
    // indirect light only for main light
    float3 indirect =
        (indirectDiffuse(baseColor, gi, kD) +
         indirectSpecular(NdV, f0, roughness, environment, kD))*ao;
    color += direct + indirect;
}

void calAddLightParams(eLightDesc lightOri, float3 pos_world, float3 normal,out float3 direction, out float3 color, out float distanceAttenuation, out float shadowAttenuation)
{
    distanceAttenuation = (float)0;

    //object to light dir
    float3 light_dir = (float3)(lightOri.position.xyz - pos_world);
    float l_dist = length(light_dir);
    light_dir /= l_dist;


    distanceAttenuation = saturate(lightOri.range_att.y + l_dist * lightOri.range_att.x);

    // spot light
    if (lightOri.diffuse.w > (float)0) 
    {
        direction = -lightOri.dir.xyz;

        float cosA = dot(-lightOri.dir.xyz, light_dir);
        if (cosA > lightOri.diffuse.w)
        {
            distanceAttenuation *= pow((cosA - lightOri.diffuse.w) * lightOri.position.w, lightOri.dir.w);
        }
        else
            distanceAttenuation = (float)0;
    }
    // point light
    else{
        direction = light_dir;
    }

    color = lightOri.diffuse.rgb;
    // TODO: additional light shadow
    shadowAttenuation = (float)1;
}

// PBR version
float3 ApplyLocalLight(int id, float3 pos_world, float3 normal, float3 viewDir, float3 baseColor, float metallic, float roughness)
{
    eLightDesc lightOri = local_lights[id];

    // additional light config
    Light addLight = (Light)0;
    calAddLightParams(lightOri,pos_world,normal,addLight.direction, addLight.color, addLight.distanceAttenuation, addLight.shadowAttenuation);

    float3 H = normalize(viewDir + addLight.direction);
    float NdV = saturate(dot(normal, viewDir));
    float HdV = saturate(dot(H, viewDir));
    float3 F = fresnelSchlick(HdV, (float)0.04);
    float3 kD = ((float)1.0 - F) * ((float)1.0 - metallic);

    return directLight(addLight, normal, H, NdV, F, kD, baseColor, roughness, metallic, false);
}

inline float3 EnvironmentColor(float3 ambient,float3 lightColor){
    
    //hack for inventory
    lightColor=lightColor==float3(0,0,0)?float3(1.0,0.892,0.761):lightColor;

    // float3 envColor=lerp(ambient,lightColor,0.6f);
    // float intensity = max(0.0001f,dot(envColor, float3(0.2126, 0.7152, 0.0722)));

    // float3 envLum=lerp(ambient,lightColor,0.4f);
    // float intensityLight=max(0.0001f,dot(envLum, float3(0.2126, 0.7152, 0.0722)));
    // return envColor / intensity * intensityLight;

    return lerp(ambient,lightColor,(float)0.4);
}