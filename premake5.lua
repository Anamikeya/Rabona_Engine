workspace "Rabona_Engine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Rabona/vendor/GLFW/include"

include "Rabona/vendor/GLFW"

project "Rabona"
	location"Rabona"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/".. outputdir .. "/%{prj.name}")
	objdir ("bin-int/".. outputdir .. "/%{prj.name}")

	pchheader "Rbpch.h"
	pchsource "Rabona/src/Rbpch.cpp"
	
	files
	{
		"Rabona/src/**.h",
		"Rabona/src/**.cpp"
	}

	includedirs
	{
		"Rabona/src",
		"Rabona/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}
	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{

			"RB_PLATFORM_WINDOWS",
			"RB_BUILD_DLL"
		}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .."/Game")
	}

	filter "configurations:Debug"
		defines "RB_DEBUG"
		symbols "on"
	
	
	filter "configurations:Release"
		defines "RB_RELEASE"
		optimize "on"
		
	filter "configurations:Dist"
		defines "RB_DIST"
		optimize "on"

project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/".. outputdir .. "/%{prj.name}")
	objdir("bin-int/".. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Rabona/vendor/spdlog/include",
		"Rabona/src"
	}

	links
	{
		"Rabona"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{

			"RB_PLATFORM_WINDOWS",
			"RB_ENABLE_ASSERTS"
		}

	filter "configurations:Debug"
	defines "RB_DEBUG"
	symbols "on"


	filter "configurations:Release"
		defines "RB_RELEASE"
		optimize "on"
		
	filter "configurations:Dist"
		defines "RB_DIST"
		optimize "on"

