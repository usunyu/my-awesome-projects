#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif




#pragma once
struct VirtActionInvoker0
{
	typedef void (*Action)(void*, const MethodInfo*);

	static inline void Invoke (Il2CppMethodSlot slot, void* obj)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		((Action)data.methodInfo->method)(data.target, data.methodInfo);
	}
};
template <typename R>
struct VirtFuncInvoker0
{
	typedef R (*Func)(void*, const MethodInfo*);

	static inline R Invoke (Il2CppMethodSlot slot, void* obj)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		return ((Func)data.methodInfo->method)(data.target, data.methodInfo);
	}
};
template <typename T1>
struct VirtActionInvoker1
{
	typedef void (*Action)(void*, T1, const MethodInfo*);

	static inline void Invoke (Il2CppMethodSlot slot, void* obj, T1 p1)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		((Action)data.methodInfo->method)(data.target, p1, data.methodInfo);
	}
};
template <typename R, typename T1>
struct VirtFuncInvoker1
{
	typedef R (*Func)(void*, T1, const MethodInfo*);

	static inline R Invoke (Il2CppMethodSlot slot, void* obj, T1 p1)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		return ((Func)data.methodInfo->method)(data.target, p1, data.methodInfo);
	}
};
template <typename T1, typename T2>
struct VirtActionInvoker2
{
	typedef void (*Action)(void*, T1, T2, const MethodInfo*);

	static inline void Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		((Action)data.methodInfo->method)(data.target, p1, p2, data.methodInfo);
	}
};
template <typename R, typename T1, typename T2>
struct VirtFuncInvoker2
{
	typedef R (*Func)(void*, T1, T2, const MethodInfo*);

	static inline R Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		return ((Func)data.methodInfo->method)(data.target, p1, p2, data.methodInfo);
	}
};
template <typename T1, typename T2, typename T3>
struct VirtActionInvoker3
{
	typedef void (*Action)(void*, T1, T2, T3, const MethodInfo*);

	static inline void Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2, T3 p3)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		((Action)data.methodInfo->method)(data.target, p1, p2, p3, data.methodInfo);
	}
};
template <typename R, typename T1, typename T2, typename T3>
struct VirtFuncInvoker3
{
	typedef R (*Func)(void*, T1, T2, T3, const MethodInfo*);

	static inline R Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2, T3 p3)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		return ((Func)data.methodInfo->method)(data.target, p1, p2, p3, data.methodInfo);
	}
};
template <typename T1, typename T2, typename T3, typename T4>
struct VirtActionInvoker4
{
	typedef void (*Action)(void*, T1, T2, T3, T4, const MethodInfo*);

	static inline void Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2, T3 p3, T4 p4)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		((Action)data.methodInfo->method)(data.target, p1, p2, p3, p4, data.methodInfo);
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4>
struct VirtFuncInvoker4
{
	typedef R (*Func)(void*, T1, T2, T3, T4, const MethodInfo*);

	static inline R Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2, T3 p3, T4 p4)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		return ((Func)data.methodInfo->method)(data.target, p1, p2, p3, p4, data.methodInfo);
	}
};
template <typename T1, typename T2, typename T3, typename T4, typename T5>
struct VirtActionInvoker5
{
	typedef void (*Action)(void*, T1, T2, T3, T4, T5, const MethodInfo*);

	static inline void Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		((Action)data.methodInfo->method)(data.target, p1, p2, p3, p4, p5, data.methodInfo);
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5>
struct VirtFuncInvoker5
{
	typedef R (*Func)(void*, T1, T2, T3, T4, T5, const MethodInfo*);

	static inline R Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		return ((Func)data.methodInfo->method)(data.target, p1, p2, p3, p4, p5, data.methodInfo);
	}
};
template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
struct VirtActionInvoker6
{
	typedef void (*Action)(void*, T1, T2, T3, T4, T5, T6, const MethodInfo*);

	static inline void Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		((Action)data.methodInfo->method)(data.target, p1, p2, p3, p4, p5, p6, data.methodInfo);
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
struct VirtFuncInvoker6
{
	typedef R (*Func)(void*, T1, T2, T3, T4, T5, T6, const MethodInfo*);

	static inline R Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		return ((Func)data.methodInfo->method)(data.target, p1, p2, p3, p4, p5, p6, data.methodInfo);
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
struct VirtFuncInvoker7
{
	typedef R (*Func)(void*, T1, T2, T3, T4, T5, T6, T7, const MethodInfo*);

	static inline R Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		return ((Func)data.methodInfo->method)(data.target, p1, p2, p3, p4, p5, p6, p7, data.methodInfo);
	}
};
template <typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
struct VirtFuncInvoker8
{
	typedef R (*Func)(void*, T1, T2, T3, T4, T5, T6, T7, T8, const MethodInfo*);

	static inline R Invoke (Il2CppMethodSlot slot, void* obj, T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8)
	{
		VirtualInvokeData data = il2cpp::vm::Runtime::GetVirtualInvokeData (slot, obj);
		return ((Func)data.methodInfo->method)(data.target, p1, p2, p3, p4, p5, p6, p7, p8, data.methodInfo);
	}
};
