// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
using System.IO;


namespace UnrealBuildTool.Rules
{
	public class G27Plugin : ModuleRules
	{
        public G27Plugin(TargetInfo Target)
		{
            PublicAdditionalLibraries.Add("atls.lib");
            
            PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					"G27Plugin/Private",
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
				"Core", 
				"CoreUObject", 
				"Engine", 
				"InputCore",
				"RHI"
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);

            LoadG27Lib(Target);
		}

       private string ModulePath
       {
           get { return Path.GetDirectoryName( RulesCompiler.GetModuleFilename( this.GetType().Name ) ); }
       }
 
        private string ThirdPartyPath
        {
            get { return Path.GetFullPath( Path.Combine( ModulePath, "../../ThirdParty/" ) ); }
        }

        public bool LoadG27Lib(TargetInfo Target)
        {
            bool isLibrarySupported = false;

            if ((Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Win32))
            {
                isLibrarySupported = true;

                string PlatformString = (Target.Platform == UnrealTargetPlatform.Win64) ? "x64" : "x86";
                string LibrariesPath = Path.Combine(ThirdPartyPath, "G27Lib", "Libraries");

                PublicAdditionalLibraries.Add(Path.Combine(LibrariesPath, "WheelLib.lib"));
            }

            if (isLibrarySupported)
            {
                // Include path
                PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "G27Lib", "Includes"));
            }

            Definitions.Add(string.Format("WITH_G27_BINDING={0}", isLibrarySupported ? 1 : 0));

            return isLibrarySupported;
        }
	}
}