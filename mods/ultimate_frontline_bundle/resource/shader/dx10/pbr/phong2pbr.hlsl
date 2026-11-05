// float colorDodge(float a,float b){
//     return a+(a*b)/(1.0f-b);
// }

//base roughness transform function
//srThreshold=smooth rough thresold
//stSmooth=strength smooth
inline float baseRoughnessT(float specular,float contrast,float srThreshold,float roughEnhance,float stSmooth)
{
    specular = lerp((float)0.5, specular, (float)1.0 + contrast);

    float isSmooth = step(srThreshold, specular);

    float roughCase = specular + roughEnhance;
    float smoothCase = specular * stSmooth;

    specular = lerp(roughCase, smoothCase, isSmooth);

    return saturate((float)1.0 - specular);
}

//for ground texture
//less roughness in rough part but a bit more in smooth part
inline void groundTextureT(float specular, out float metallic, out float roughness)
{
    // UFB: legacy wet/snow specular maps are not metal; metallic ground turned
    // white snow and wet mud into a white mirror. Was saturate(2 * specular - 1).
    metallic = (float)0.0;

    const float contrast = 0.2;
    const float srThreshold = 0.5;
    const float roughEnhance = 0.1;
    const float stSmooth = 1.0;

    roughness=baseRoughnessT(specular,contrast,srThreshold,roughEnhance,stSmooth);
}

//for flora and ground stamp
//need some fix here, two-sided model will get bug under current pipeline
inline void floraT(float specular, out float metallic, out float roughness)
{
    // UFB: foliage and ground stamps are dielectric. Was saturate(1.5 * specular - 1).
    metallic = (float)0.0;

    const float contrast = 0.2;
    const float srThreshold = 0.5;
    const float roughEnhance = 0.3;
    const float stSmooth = 0.9;

    roughness=baseRoughnessT(specular,contrast,srThreshold,roughEnhance,stSmooth);
}

//unviersal transform for most of models
inline void universalT(float specular, out float metallic, out float roughness)
{
    metallic = saturate((float)2.0 * specular - (float)1.0);

    const float contrast = 0.2;
    const float srThreshold = 0.5;
    const float roughEnhance = 0.4;
    const float stSmooth = 0.9;

    roughness=baseRoughnessT(specular,contrast,srThreshold,roughEnhance,stSmooth);
}

// This function could be vary in different mods
// I make this one for general transform, but you can make your own one!
inline void phong2pbr(float specular, out float metallic, out float roughness)
{
#if defined(LAYERED) // ground texture
    groundTextureT(specular, metallic, roughness);
#elif defined(NEED_ALPHA) && !defined(ALPHA_TEST) // flora
    floraT(specular, metallic, roughness);
#else                                             // universal
    universalT(specular, metallic, roughness);
#endif

#if defined(WATER)
    // UFB: water gets specular 1.0, which the universal branch made full chrome.
    metallic = (float)0.0;
#endif

    // for debug
    //  roughness=pow(roughness, 2.2f);
}