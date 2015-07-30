Up and Running with OpenGL
==========================

#### Setting up OpenGL and CMake in OS X
1. Download CMake: http://www.cmake.org/download/
2. cd into the CMake file directory


          	$ ./bootstrap && make && make install
3. Use CMake to generate an Xcode project file:


			$ mkdir xcode
			$ cd xcode
			$ cmake -G "Xcode" ..

