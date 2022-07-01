project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    files {
        "**.h",
        "**.hpp",
        "**.c",
        "**.cc",
        "**.cpp"
    }

    includedirs {
        ".",
        "%{wks.location}/ThirdParty/include",
        "%{wks.location}/WTGD/src"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "on"

        libdirs {
            "%{wks.location}/ThirdParty/libs/x86"
        }

        links{
            outdir .. "/WTGD.lib",
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
            outdir .. "/WTGD.lib",
            "sfml-system.lib",
            "sfml-main.lib",
            "sfml-window.lib",
            "sfml-graphics.lib"
        }