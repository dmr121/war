# War
**Created by: David Rozmajzl**
Written in C++ (minimum required version is C++11)

## How to compile
You can write your own Makefile and compile your program with that, but the easiest way to compile and run this program is to use [cmake](https://cmake.org/download/).

Navigate to the build folder in the shell. Run this command:

    $ cmake ..

This generates a Makefile specifically for your platform automatically. While still in the build folder,
run this:
    
    $ make

This compiles the program and make an executable called **war**

## How to run
After creating your executable, you can simply run it with:

    $ ./war

To get a more detailed description of what's going on in the game, run it with the *-v* argument

    $ ./war -v


NOTE: I compiled and ran my program on a MacBook. This has not been tested
      on Windows.