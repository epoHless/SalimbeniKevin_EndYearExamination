project "WTGD"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"

    defines {
        "DLL_EXPORT"
    }

    files {
        "src/**.h",
        "src/**.hpp",
        "src/**.c",
        "src/**.cc",
        "src/**.cpp"
    }

    -- precompiled headers
    pchheader "pch.h"
    pchsource "src/pch.cpp"

    includedirs {
        "%{prj.location}/src",
        "%{wks.location}/ThirdParty/include"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "on"

        libdirs {
            "%{wks.location}/ThirdParty/libs/x86"
        }

        links{
            "sfml-system-d.lib",
            "sfml-main-d.lib",
            "sfml-window-d.lib",
            "sfml-graphics-d.lib"
        }

    filter "configurations:Release"
        defines "RELEASE"
        optimize "on"

        libdirs {
            "%{wks.location}/ThirdParty/libs/x86_64"
        }

        links {
            "sfml-system.lib",
            "sfml-main.lib",
            "sfml-window.lib",
            "sfml-graphics.lib"
        }