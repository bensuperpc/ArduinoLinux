# ArduinoLinux

### _It's lib who you can build and execute arduino codes on Linux_

[![N|Solid](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://isocpp.org/) [![N|Solid](https://forthebadge.com/images/badges/made-with-c.svg)](https://isocpp.org/) [![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com) 

[![CMake](https://github.com/Bensuperpc/ArduinoLinux/actions/workflows/cmake.yml/badge.svg?event=push)](https://github.com/Bensuperpc/ArduinoLinux/actions/workflows/cmake.yml)

# New Features !

  - Build with some arduino code

### Tech

ArduinoLinux uses a number of open source projects to work properly:

* [Clang] - Clang 10.0 compiler (or GCC 10 min)
* [Boost] - Make units tests and others things :)
* [CMake] - Build system.
* [OpenMP] - Multi-threading lib. (Not mandatory but really recommended !)
* [Docker] - Container system (if you use it).
* [TLO] - Linker (To replace gold linker)

You can see my [public repository][ben_github] on GitHub, and can see my [public repository][ben_gitlab] on GitLab.

#### Building for source
You need to install SFML, OpenCV, BoostLib, OpenGL lib, Qt 5.12 or newer, GCC and G++ (With C++17 support), before build.

```sh
git clone https://github.com/Bensuperpc/ArduinoLinux.git
```

```sh
cd ArduinoLinux
```

For production release:
```sh
./make.sh -DCMAKE_BUILD_TYPE=Release
```

For minisize release:
```sh
./make.sh -DCMAKE_BUILD_TYPE=MinSizeRel
```

For debug release:
```sh
./make.sh -DCMAKE_BUILD_TYPE=Debug
```

For converage release:
```sh
./make.sh -DCMAKE_BUILD_TYPE=Coverage
```
```sh
./coverage.sh
```

### Docker
WIP

### Todos

 - Write MORE Tests
 - Continue dev. :D

License
----

[MIT] License


**Free Software forever !**

   [Boost]: <https://www.boost.org>
   [OpenMP]: <https://www.openmp.org/>
   [CMake]: <https://cmake.org/>
   [Docker]: <https://www.docker.com/>
   [TLO]: <https://gcc.gnu.org/wiki/LinkTimeOptimization>
   [Clang]: <https://clang.llvm.org/>
   [ben_github]: <https://github.com/Bensuperpc>
   [ben_gitlab]: <https://gitlab.com/Bensuperpc>
   [MIT]: LICENSE
   
 
