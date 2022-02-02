workspace "Rabona_Engine"
	architecture "x64"
	startproject "Game"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Rabona/vendor/GLFW/include"
IncludeDir["Glad"] = "Rabona/vendor/Glad/include"
IncludeDir["ImGui"] = "Rabona/vendor/imgui"
IncludeDir["glm"] = "Rabona/vendor/glm"

include "Rabona/vendor/GLFW"
include "Rabona/vendor/Glad"
include "Rabona/vendor/imgui"


project "Rabona"
	location"Rabona"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/".. outputdir .. "/%{prj.name}")
	objdir ("bin-int/".. outputdir .. "/%{prj.name}")

	pchheader "Rbpch.h"
	pchsource "Rabona/src/Rbpch.cpp"
	
	files
	{
		"Rabona/src/**.h",
		"Rabona/src/**.cpp",
		"Rabona/vendor/glm/glm/**.hpp",
		"Rabona/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"Rabona/src",
		"Rabona/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{

			"RB_PLATFORM_WINDOWS",
			"RB_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} \"../bin/" ..outputdir .."/Game/\"")
	}

	filter "configurations:Debug"
		defines "RB_DEBUG"
		runtime "Debug"
		symbols "on"
	
	
	filter "configurations:Release"
		defines "RB_RELEASE"
		runtime "Release"
		optimize "on"
		
	filter "configurations:Dist"
		defines "RB_DIST"
		runtime "Release"
		optimize "on"

project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"Rabona/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Rabona"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines
		{

			"RB_PLATFORM_WINDOWS",
			"RB_ENABLE_ASSERTS"
		}

	filter "configurations:Debug"
		defines "RB_DEBUG"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		defines "RBs_RELEASE"
		runtime "Release"
		optimize "on"
		
	filter "configurations:Dist"
		defines "RB_DIST"
		runtime "Release"
		optimize "on"

