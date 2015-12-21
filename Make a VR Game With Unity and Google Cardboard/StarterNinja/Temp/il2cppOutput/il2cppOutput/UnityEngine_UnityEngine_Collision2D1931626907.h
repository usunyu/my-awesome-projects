#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.Rigidbody2D
struct Rigidbody2D_t816092662_0;
// UnityEngine.Collider2D
struct Collider2D_t1988002255_0;
// UnityEngine.ContactPoint2D[]
struct ContactPoint2DU5BU5D_t381302861_0;

#include "mscorlib_System_Object_887538054.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"

// UnityEngine.Collision2D
struct  Collision2D_t1931626907_0  : public Object_t
{
	// UnityEngine.Rigidbody2D UnityEngine.Collision2D::m_Rigidbody
	Rigidbody2D_t816092662_0 * ___m_Rigidbody_0;
	// UnityEngine.Collider2D UnityEngine.Collision2D::m_Collider
	Collider2D_t1988002255_0 * ___m_Collider_1;
	// UnityEngine.ContactPoint2D[] UnityEngine.Collision2D::m_Contacts
	ContactPoint2DU5BU5D_t381302861_0* ___m_Contacts_2;
	// UnityEngine.Vector2 UnityEngine.Collision2D::m_RelativeVelocity
	Vector2_t_725341338_0  ___m_RelativeVelocity_3;
	// System.Boolean UnityEngine.Collision2D::m_Enabled
	bool ___m_Enabled_4;
};
