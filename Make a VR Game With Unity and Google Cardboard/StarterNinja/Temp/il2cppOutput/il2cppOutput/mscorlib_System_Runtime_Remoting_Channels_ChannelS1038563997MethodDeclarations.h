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

// System.Runtime.Remoting.Messaging.IMessageSink
struct IMessageSink_t1677259445_0;
// System.String
struct String_t;
// System.Object
struct Object_t;
// System.Runtime.Remoting.Channels.IChannelSender
struct IChannelSender_t928933779_0;
// System.Object[]
struct ObjectU5BU5D_t1774424924_0;
// System.Runtime.Remoting.Channels.IChannel
struct IChannel_t_302864450_0;
// System.Runtime.Remoting.ChannelData
struct ChannelData_t_565445965_0;
// System.Runtime.Remoting.ProviderData
struct ProviderData_t_661904747_0;

#include "codegen/il2cpp-codegen.h"

// System.Void System.Runtime.Remoting.Channels.ChannelServices::.cctor()
extern "C"  void ChannelServices__cctor_m1558856244_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageSink System.Runtime.Remoting.Channels.ChannelServices::CreateClientChannelSinkChain(System.String,System.Object,System.String&)
extern "C"  Object_t * ChannelServices_CreateClientChannelSinkChain_m_1531041065_0 (Object_t * __this /* static, unused */, String_t* ___url, Object_t * ___remoteChannelData, String_t** ___objectUri, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Runtime.Remoting.Messaging.IMessageSink System.Runtime.Remoting.Channels.ChannelServices::CreateClientChannelSinkChain(System.Runtime.Remoting.Channels.IChannelSender,System.String,System.Object[],System.String&)
extern "C"  Object_t * ChannelServices_CreateClientChannelSinkChain_m_976348860_0 (Object_t * __this /* static, unused */, Object_t * ___sender, String_t* ___url, ObjectU5BU5D_t1774424924_0* ___channelDataArray, String_t** ___objectUri, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Channels.ChannelServices::RegisterChannel(System.Runtime.Remoting.Channels.IChannel)
extern "C"  void ChannelServices_RegisterChannel_m1343018521_0 (Object_t * __this /* static, unused */, Object_t * ___chnl, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Channels.ChannelServices::RegisterChannel(System.Runtime.Remoting.Channels.IChannel,System.Boolean)
extern "C"  void ChannelServices_RegisterChannel_m409692228_0 (Object_t * __this /* static, unused */, Object_t * ___chnl, bool ___ensureSecurity, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void System.Runtime.Remoting.Channels.ChannelServices::RegisterChannelConfig(System.Runtime.Remoting.ChannelData)
extern "C"  void ChannelServices_RegisterChannelConfig_m2055899810_0 (Object_t * __this /* static, unused */, ChannelData_t_565445965_0 * ___channel, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object System.Runtime.Remoting.Channels.ChannelServices::CreateProvider(System.Runtime.Remoting.ProviderData)
extern "C"  Object_t * ChannelServices_CreateProvider_m463156604_0 (Object_t * __this /* static, unused */, ProviderData_t_661904747_0 * ___prov, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Object[] System.Runtime.Remoting.Channels.ChannelServices::GetCurrentChannelInfo()
extern "C"  ObjectU5BU5D_t1774424924_0* ChannelServices_GetCurrentChannelInfo_m_211039022_0 (Object_t * __this /* static, unused */, const MethodInfo* method) IL2CPP_METHOD_ATTR;
