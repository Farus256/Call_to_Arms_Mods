#ifdef LAYER1
#define LAYERED
#endif

#if defined(SOFT_INTERSECT) || defined(WATER_OPTICS)
Texture2D vsDepth_BUFFER : register(t10);
SamplerState vsDepth_SAMPLER : register(s10);
#endif

#ifdef ENVMAP
 #ifdef WATER
  #ifdef REAL_REFLECTION
	Texture2D texEnvmap		: register(t3);
  #else
	TextureCube texEnvmap	: register(t3);
  #endif //REAL_REFLECTION
	SamplerState samEnvmap	: register(s3);
 #else
	TextureCube texEnvmap	: register(t2);
	SamplerState samEnvmap	: register(s2);
	#if defined(MASK)
		Texture2D texMask	: register(t3);
		#define samMask samDiffuse0
	#endif //defined(MASK)
 #endif //WATER
#endif //ENVMAP

#ifdef NEED_NORMAL
static	float3 normal_w;
#endif

Texture2D texDiffuse0 : register(t0);

#if defined(LIGHTMAP) || defined(TEXMUL) || defined(TEXMORPH)
Texture2D texDiffuse1 : register(t1);
#endif

#ifdef NEED_TANGENT
  #ifdef BUMP
	Texture2D texNormal0 : register(t2);
	#define samNormal0 samDiffuse0
  #endif
	static	float3 tangent_w;
	static	float3 binormal_w;
float3 FromTangentSpace(float3 ts)
{
	return tangent_w * ts.x + binormal_w * ts.y + normal_w * ts.z;
}
float3 ToTangentSpace(float3 ws)
{
	return float3(dot(ws, tangent_w), dot(ws, binormal_w), dot(ws, normal_w));
}
#endif

#ifdef SPEC
 	Texture2D texSpecular0 : register(t3);
 	#define  samSpecular0 samDiffuse0
#endif

#ifdef LAYER1
	Texture2D texDiffuse1 : register(t5);
 #ifdef BUMP
	Texture2D texNormal1 : register(t7);
	#define samNormal1 samDiffuse1
 #endif
 #ifdef SPEC
	Texture2D texSpecular1 : register(t8);
	#define samSpecular1 samDiffuse1
 #endif
#endif

#if defined(GLOBAL_NORMALMAP) || defined(GLOBAL_DIFFUSEMAP)
	SamplerState samGlobalMap : register(s9);
#endif

#ifdef GLOBAL_NORMALMAP
	Texture2D texNormalG : register(t17);
#endif
#ifdef GLOBAL_DIFFUSEMAP
	Texture2D texDiffuseG : register(t16);
#endif

float3 UnpackNormal(float4 n)
{
#ifdef WATER
  return n.rgb * 2 - 1;
#elif !defined(UNSWIZZLED_NM)
 return n.agb * 2 - 1;
#else
 float3 un;
 un.rg = n.gr * 2 - 1;	//NOTE: ATI2 has R and G channels swapped compared to BC5, so we assume we have an ATI2 input
 un.b = sqrt(1 - un.r*un.r - un.g*un.g);
 return un;
#endif
}

#ifdef LAYERED
#define CONDITION(name, id) if(name##id)
#else
#define CONDITION(name, id)
#endif

#ifdef PARALLAX
#define CALC_PARALLAX(id)	\
	CONDITION(prlx, id)		\
	{						\
		ApplyParallax(tc, view_dir_ts, k_steps, texHeight##id, samHeight##id, parallax_params##id);\
	}
#else
#define	CALC_PARALLAX(id)
#endif

#ifdef DIFFUSE
// disable lightmap when envmap is enable

//use dif1.b= use blue channel of lightmap, which can both compatible with regular lightmaps/mask maps
#if defined(TEXMUL)
#define CALC_DIFFUSE(id)									\
	float4 dif0 = texDiffuse0.Sample(samDiffuse0, tc_base);	\
	float4 dif1 = texDiffuse1.Sample(samDiffuse1, tc_base1);\
	mtl.diffuse = dif0 * dif1 * mtl_params.y;		
#elif defined(LIGHTMAP) && !defined(PBR) && !defined(PBR_LITE)
#define CALC_DIFFUSE(id)									\
	float4 dif0 = texDiffuse0.Sample(samDiffuse0, tc_base);	\
	float4 dif1 = texDiffuse1.Sample(samDiffuse1, tc_base1);\
	mtl.diffuse.rgb = dif0.rgb * dif1.b * mtl_params.y;		\
	mtl.diffuse.a = dif0.a * mtl_params.y;
#elif defined(TEXMORPH)
#define CALC_DIFFUSE(id)									\
	float4 dif0 = texDiffuse0.Sample(samDiffuse0, tc_base);	\
	float4 dif1 = texDiffuse1.Sample(samDiffuse1, tc_base1);\
	mtl.diffuse = lerp(dif1, dif0, morphK.x);		
#else
#define CALC_DIFFUSE(id)	\
	mtl.diffuse += texDiffuse##id.Sample(samDiffuse##id, tc) * k##id; 
#endif
#elif defined(WATER)
#define CALC_DIFFUSE(id)	\
	mtl.diffuse = waterDiffuse;
#else
#define CALC_DIFFUSE(id)	\
	mtl.diffuse = 1.0f;
#endif //DIFFUSE

#ifdef ENVMAP
 #if defined(MASK)
	#define	ENV_AMOUNT texMask.Sample(samMask, tc).rgb
 #else
	#define	ENV_AMOUNT env_amount.rgb
 #endif

//*FH: i need the reflect amount in he output for blending refraction with reflection.
//	   Therfore, i use a float 4 if water is defined and store the reflection amount in the .a/.w channel
#ifdef WATER_OPTICS
float4 CalcEmissive(vsOut _in, float3 mtl_normal, float2 tc)
{
#else
float3 CalcEmissive(vsOut _in, float3 mtl_normal, float2 tc)
{
#endif
 #ifdef REAL_REFLECTION
	float2 uv = (_in.position_proj.xy / _in.position_proj.w) * float2(0.5, -0.5) + 0.5f;
	float reflection_scale = 0.1f;
	uv += mtl_normal.xy * reflection_scale;
	float3 reflection = texEnvmap.Sample(samEnvmap, uv).rgb;
 #else
	float3 tc_cube = reflect(view_dir, mtl_normal).xzy;
	tc_cube.xy *= -1;
	float3 reflection = texEnvmap.Sample(samEnvmap, tc_cube).rgb;
 #endif
	float reflect_amount = 1.0f;
 #ifdef WATER
	reflect_amount = 1.0f - dot(mtl_normal, view_dir);
// 	float fresnel_scale = 1.0f;
// 	float fresnel_power = 1.0f;
// 	reflect_amount = pow(abs(reflect_amount) * fresnel_scale, fresnel_power);
 #endif
 #ifdef WATER_OPTICS
	return float4(reflection * reflect_amount * ENV_AMOUNT,reflect_amount);
 #else
	return reflection * reflect_amount * ENV_AMOUNT;
 #endif
}
#endif //ENVMAP

#ifdef LIGHT
#ifdef BUMP
#define CALC_BUMP(id)	\
	float3 normal##id = normal_w;		\
 	if(bump##id)						\
	{									\
		normal##id = UnpackNormal(texNormal##id.Sample(samNormal##id, tc));	\
		normal##id = FromTangentSpace(normal##id);	\
	}									\
	mtl.normal += normal##id * k##id;
#else
#define	CALC_BUMP(id)				\
	mtl.normal += normal_w * k##id;
#endif //BUMP

#ifdef SPEC

  #ifdef FULL_SPECULAR
	#define SPECULAR_FROM_TEX(id)	texSpecular##id.Sample(samSpecular##id, tc).rgb
	#define GLOSS_FROM_TEX(id)		texSpecular##id.Sample(samSpecular##id, tc).a
  #else
	#define SPECULAR_FROM_TEX(id)	texSpecular##id.Sample(samSpecular##id, tc).r
	#define GLOSS_FROM_TEX(id)		1.0
  #endif

// environment parameters no longer affect specular because goh will force add {"specular color" "black"} to any vehicles saved in dynamic campign.
//this will let specular = 0
// specular##id = clamp(materialSpecular##id.rgb,0,1.5f) * SPECULAR_FROM_TEX(id);
// mtl.specular_power += specular_pow##id * materialSpecular##id.a * k##id;
#define	CALC_SPEC(id)									\
	float3 specular##id = 0;							\
	float specular_pow##id = 1;							\
	CONDITION(spec, id)									\
	{													\
		specular##id = SPECULAR_FROM_TEX(id);	\
		specular_pow##id = GLOSS_FROM_TEX(id);			\
	}													\
	mtl.specular += specular##id * k##id;				\
	mtl.specular_power += specular_pow##id * k##id;
#elif defined(WATER)
#define	CALC_SPEC(id)			\
	mtl.specular = 1.0f;		\
	mtl.specular_power = 1000.0f;
#else
#define	CALC_SPEC(id)
#endif //SPEC
#else
#define	CALC_BUMP(id)
#define	CALC_SPEC(id)
#endif //LIGHT

bool AnyNaN(float3 v)
{
    uint3 bits = asuint(v) & 0x7fffffff;
    return any(bits > 0x7f800000);
}

eMaterialOutput CalcMaterial(vsOut _in)
{
	eMaterialOutput mtl;
	mtl.normal				= 0;
	mtl.diffuse				= 0;
	mtl.emissive			= 0;
	mtl.specular			= 0;
	mtl.specular_power		= 0;
	mtl.reflectionAmount	= 0;
	mtl.roughness			= 0;
	mtl.ao					= 0;

#if TEXCOORDS > 0
	float2 tc_base = _in.texCoord;
#ifdef TEX_BLEND
	tc_base *= TEXTURTILING;
#endif
	float2 tc_base1 = tc_base;
#if !defined(REAL_REFLECTION) && TEXCOORDS > 1
	tc_base1 = _in.texCoord1;
#endif
	float2 tc = tc_base;
#endif

#ifdef NEED_NORMAL
	normal_w = normalize(_in.normal * 2 - 1);
#endif
#ifdef NEED_TANGENT
	//original approach
	// tangent_w = normalize(_in.tangent);
	// binormal_w =	normalize(_in.binormal);

	//now we manually calculate tangent/binormal
    float3 pos_dx = ddx(_in.pos_world);
    float3 pos_dy = ddy(_in.pos_world);
    float2 tex_dx = ddx(_in.texCoord);
    float2 tex_dy = ddy(_in.texCoord);

    float3 t = (tex_dy.y * pos_dx - tex_dx.y * pos_dy);
    float3 b = (tex_dx.x * pos_dy - tex_dy.x * pos_dx);

    tangent_w = normalize(t - dot(t, normal_w) * normal_w);

    float handedness = dot(cross(normal_w, tangent_w), b) < 0.0f ? -1.0f : 1.0f;
    
    binormal_w = cross(normal_w, tangent_w) * handedness;
#endif

	float k0 = 1;
#ifdef LAYERED
	k0 = _in.color.a;
#endif

#if defined(PARALLAX) && !defined(PBR)
	float3 view_dir_ts = ToTangentSpace(view_dir);
#ifdef TEX_BLEND
	// UFB: terrain parallax uses the vanilla basis. Vanilla vs.hlsl gives untangented terrain T = world X and
	// B = cross(T, N); the Workshop PBR derivative tangents reverse one axis there, so the ground slid and
	// stretched with the camera. Lighting keeps the Workshop basis; only the parallax view vector changes.
	{
		float3 ufb_t = float3(1, 0, 0);
		float3 ufb_b = normalize(cross(ufb_t, normal_w));
		view_dir_ts = float3(dot(view_dir, ufb_t), dot(view_dir, ufb_b), dot(view_dir, normal_w));
	}
#endif
	float k_steps = dot(view_dir, normal_w);
#endif

#if defined(GLOBAL_NORMALMAP) || defined(GLOBAL_DIFFUSEMAP)
	float2 tc_global;
  	tc_global.x = (_in.pos_world.x - posWtoTexX.x) * posWtoTexX.y;
  	tc_global.y = (_in.pos_world.y - posWtoTexY.x) * posWtoTexY.y;
#endif

#ifdef GLOBAL_NORMALMAP
	float3 global_nm_w = FromTangentSpace(UnpackNormal(texNormalG.Sample(samGlobalMap, tc_global)));
	normal_w = global_nm_w;
#endif

	#if !defined(PBR) && !defined(PBR_LITE)
		CALC_PARALLAX(0);
	#endif
	CALC_DIFFUSE(0);	
 	CALC_BUMP(0);
 	CALC_SPEC(0);

#ifdef LAYER1
	float k1 = 1 - _in.color.a;
	tc = tc_base;
	CALC_PARALLAX(1);
	CALC_DIFFUSE(1);	
	CALC_BUMP(1);
	CALC_SPEC(1);
#endif

#ifdef GLOBAL_DIFFUSEMAP
	float3 global_diffuse = texDiffuseG.Sample(samGlobalMap, tc_global).rgb;
	mtl.diffuse.rgb *= global_diffuse;
#endif

	mtl.normal = normalize(mtl.normal);
#ifdef NEED_NORMAL
	//auto check if normal is Nan

	// if(AnyNaN(mtl.normal)==true){
	// 	mtl.normal=normal_w;
	// }

	//maybe better
	uint m = 0u - AnyNaN(mtl.normal);
	uint3 mask = uint3(m, m, m);

	uint3 bumpN = asuint(mtl.normal);
	uint3 defaultN = asuint(normal_w);

	mtl.normal = asfloat((bumpN & ~mask) | (defaultN & mask));
#endif

#ifdef ENVMAP
	#ifdef WATER_OPTICS
		float4 emissionNreflection = CalcEmissive(_in, mtl.normal, tc);
		mtl.emissive = emissionNreflection.rgb;
		mtl.reflectionAmount = emissionNreflection.a;
	#else
		mtl.emissive = CalcEmissive(_in, mtl.normal, tc);
	#endif
#endif

#if defined(PBR)
	float3 pbrConfig=texDiffuse1.Sample(samDiffuse0, tc).rgba;
	mtl.roughness=pbrConfig.r;
	mtl.ao=pbrConfig.b;
#endif

#ifdef TFACTOR
	mtl.diffuse *= tFactor;
#endif	

#ifdef USE_VCOLOR
	mtl.diffuse *= _in.color;
	#ifdef ALPHA_TEST_PREMULTIPLIED
		mtl.diffuse.rgb *= _in.color.a;
	#endif
#endif	

	return mtl;
}