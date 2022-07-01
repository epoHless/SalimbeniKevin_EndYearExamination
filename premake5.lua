workspace "WTGD"
    -- x86_64 will be deprecated soon - better x64
    architecture "x64"
    
    configurations {
        "Debug", 
        "Release", 
        "Ship"
    }

    startproject "Sandbox"

    targetdir "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"
    objdir "%{wks.location}/int/%{cfg.buildcfg}-%{cfg.architecture}"
    
    -- same as targetdir but useable with strings
    outdir = "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"

    filter {"configurations:Debug", "architecture:x64"}
        postbuildmessage "copy x86 libs..."
        postbuildcommands {
            "{COPY} %{wks.location}/ThirdParty/libs/x86/*.dll " .. outdir
        }

    filter {"configurations:Release", "architecture:x64"}

        postbuildcommands {
            "{COPY} %{wks.location}/ThirdParty/libs/x86_64/*.dll " .. outdir 
        }

    include "WTGD/wtgd.lua"
    include "Sandbox/sandbox.lua"