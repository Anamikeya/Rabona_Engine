#pragma once

#ifdef RB_PLATFORM_WINDOWS
	#ifdef RB_BUILD_DLL
		#define RABONA_API __declspec(dllexport)
	#else
		#define RABONA_API __declspec(dllimport)
	#endif
#else
	#error Rabona only supports windows
#endif