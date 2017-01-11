// Upgrade NOTE: replaced '_World2Object' with 'unity_WorldToObject'


#define NORMAL_TO_WORLD( normal ) normalize( mul( float4( normal, 1.0 ), unity_WorldToObject ).xyz )