# Dev setup

To setup the environment, you will first need to install CMake on https://cmake.org/download/. Then, you will need to make sure you have **x86_64-w64-mingw32-g++** installed. To install it, go to https://www.msys2.org/ and download the installer. Once you have it installed, open the **MSYS2 MINGW64** console and run the following commands:

### To update the packages
```
pacman -Syu
```

### To install CMake
```
pacman -S mingw-w64-x86_64-cmake
```

### To install x86_64-w64-mingw32-g++
```
pacman -S mingw-w64-x86_64-toolchain
```

### Install GDB (for debugging)
```
pacman -S mingw-w64-x86_64-gdb
```