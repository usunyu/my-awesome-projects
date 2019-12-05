How to use ML Music Service Example:

For automatic setup, see the following steps.

1) Click on the Setup Music Service Example button under the
   MagicLeap drop down menu in the Unity Editor

   Verify that it built successfully by checking the console. The following line
   should appear:

   "Successfully setup project for music service example."

2) Build and run the MusicService example without modifying
   the bundle identifier on the player settings.

For manual setup, see the following steps.

1) Copy following songs;
    Tune1.mp3
    Tune2.mp3
    Tune3.ogg
   from Assets\MagicLeap\BackgroundMusicExample\StreamingAssets\BackgroundMusicExample
   to Assets\StreamingAssets\BackgroundMusicExample

2) Use the music_manifest.xml from Assets\MagicLeap\BackgroundMusicService, rename it
   to manifest.xml, and put in Assets\Plugins\Lumin\

3) You can build ExampleMusicProvider by calling mabu on the ExampleMusicProvider.mabu like so;
    mabu <path/to/Assets/MagicLeap/BackgroundMusicExample/ExampleMusicProvider.mabu> -t device

   This will generate the binary, named "ExampleMusicProvider" in a .out folder
   which you can move to the root of the Unity project.

4) Follow standard building procedures for a single scene, making sure music service
   scene is in build settings, and setting your bundle identifier (com.magicleap.unitymusicexample, for instance)

5) Modify the project *.package. This only gets generated at build time when none currently exist.
   You may have to build once to create it first, then modify, then build again to use the modified one.
   Add the following under ######### DO NOT EDIT ABOVE #########

DATAS= \
    ExampleMusicProvider : bin/ \

6) After building, open the mpk and verify that "ExampleMusicProvider" is in the mpk in the bin
   folder, beside Player.elf. Verify the correct manifest is in there with two components.

7) Launch on device. This will launch both components. If you attempt to terminate this
   application, the second component (the music provider) will be stuck open and will
   result in AllocFailed if you try to launch again.
    You need to execute terminate twice:
    mldb terminate unity.package.name.here .fullscreen
    mldb terminate unity.package.name.here .example_music_provider
