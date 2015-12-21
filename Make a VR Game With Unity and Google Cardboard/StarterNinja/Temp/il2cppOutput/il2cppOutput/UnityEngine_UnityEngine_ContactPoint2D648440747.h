#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Collider2D
struct Collider2D_t1988002255_0;

#include "mscorlib_System_ValueType_103494864.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// UnityEngine.ContactPoint2D
struct  ContactPoint2D_t648440747_0 
{
	// UnityEngine.Vector2 UnityEngine.ContactPoint2D::m_Point
	Vector2_t_725341338_0  ___m_Point_0;
	// UnityEngine.Vector2 UnityEngine.ContactPoint2D::m_Normal
	Vector2_t_725341338_0  ___m_Normal_1;
	// UnityEngine.Collider2D UnityEngine.ContactPoint2D::m_Collider
	Collider2D_t1988002255_0 * ___m_Collider_2;
	// UnityEngine.Collider2D UnityEngine.ContactPoint2D::m_OtherCollider
	Collider2D_t1988002255_0 * ___m_OtherCollider_3;
};
