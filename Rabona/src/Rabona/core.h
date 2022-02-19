#pragma once

#ifdef RB_PLATFORM_WINDOWS

#if HZ_DYNAMIC_LINK
	#ifdef RB_BUILD_DLL
		#define RABONA_API __declspec(dllexport)
	#else
		#define RABONA_API __declspec(dllimport)
	#endif
#else
	#define RABONA_API
#endif
	#else
		#error Rabona only supports windows

#endif


#ifdef RB_DEBUG
	#define RB_ENABLE_ASSERTS
#endif

#ifdef RB_ENABLE_ASSERTS
	#define RB_ASSERT(x, ...){if(!(x)) {RB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define RB_CORE_ASSERT(x, ...){if(!(x)) {RB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define RB_ASSERT(x, ...)
	#define RB_CORE_ASSERT(x, ...)
#endif // DEBUG



#define BIT(x) (1<<x)
#define RB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)