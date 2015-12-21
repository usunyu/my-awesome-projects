#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// GazeInputModule
struct GazeInputModule_t_1397820490_0;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_Vector2_725341338.h"
#include "UnityEngine_UnityEngine_Vector3_725341337.h"

// System.Void GazeInputModule::.ctor()
extern "C"  void GazeInputModule__ctor_m1046273690_0 (GazeInputModule_t_1397820490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean GazeInputModule::ShouldActivateModule()
extern "C"  bool GazeInputModule_ShouldActivateModule_m90977672_0 (GazeInputModule_t_1397820490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GazeInputModule::DeactivateModule()
extern "C"  void GazeInputModule_DeactivateModule_m_832669206_0 (GazeInputModule_t_1397820490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Boolean GazeInputModule::IsPointerOverGameObject(System.Int32)
extern "C"  bool GazeInputModule_IsPointerOverGameObject_m_562485931_0 (GazeInputModule_t_1397820490_0 * __this, int32_t ___pointerId, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GazeInputModule::Process()
extern "C"  void GazeInputModule_Process_m_1000689497_0 (GazeInputModule_t_1397820490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GazeInputModule::CastRayFromGaze()
extern "C"  void GazeInputModule_CastRayFromGaze_m432849490_0 (GazeInputModule_t_1397820490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GazeInputModule::UpdateCurrentObject()
extern "C"  void GazeInputModule_UpdateCurrentObject_m_1566715001_0 (GazeInputModule_t_1397820490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GazeInputModule::PlaceCursor()
extern "C"  void GazeInputModule_PlaceCursor_m_534119819_0 (GazeInputModule_t_1397820490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GazeInputModule::HandleDrag()
extern "C"  void GazeInputModule_HandleDrag_m461122854_0 (GazeInputModule_t_1397820490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GazeInputModule::HandlePendingClick()
extern "C"  void GazeInputModule_HandlePendingClick_m1735452131_0 (GazeInputModule_t_1397820490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void GazeInputModule::HandleTrigger()
extern "C"  void GazeInputModule_HandleTrigger_m1721205544_0 (GazeInputModule_t_1397820490_0 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// UnityEngine.Vector2 GazeInputModule::NormalizedCartesianToSpherical(UnityEngine.Vector3)
extern "C"  Vector2_t_725341338_0  GazeInputModule_NormalizedCartesianToSpherical_m_1146592487_0 (GazeInputModule_t_1397820490_0 * __this, Vector3_t_725341337_0  ___cartCoords, const MethodInfo* method) IL2CPP_METHOD_ATTR;
