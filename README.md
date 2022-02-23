# TribeEngine

## How to use
### Installing VCPKG
This project uses VCPKG, for more information on installation of VCPKG go to my [Basic-VCPKG-guide](https://github.com/Tboske/Basic-VCPKG-guide/blob/main/README.md).


### Packages to install 
You need multiple packages to use the Tribe Engine. Here I will list all the commands needed to install the packages via VCPKG. 
The [Basic-VCPKG-guide](https://github.com/Tboske/Basic-VCPKG-guide/blob/main/README.md) I've written also contains the basic commands and where you execute those commands.

- `vcpkg install glm`
- `vcpkg install glm --triplet=x64-windows`
- `vcpkg install imgui`
- `vcpkg install imgui --triplet=x64-windows`
- `vcpkg install imgui[opengl2-binding] --recurse`
- `vcpkg install imgui[opengl2-binding] --recurse --triplet=x64-windows`
- `vcpkg install imgui[sdl2-binding] --recurse`
- `vcpkg install imgui[sdl2-binding] --recurse --triplet=x64-windows`
- `vcpkg install opengl`
- `vcpkg install opengl --triplet=x64-windows`
- `vcpkg install SDL2`
- `vcpkg install SDL2 --triplet=x64-windows`
- `vcpkg install SDL2-ttf`
- `vcpkg install SDL2-ttf --triplet=x64-windows`
- `vcpkg install SDL2-image`
- `vcpkg install SDL2-image --triplet=x64-windows`
- `vcpkg install sdl2-image[libjpeg-turbo] --recurse`
- `vcpkg install sdl2-image[libjpeg-turbo] --recurse --triplet=x64-windows`

After having installed all these packages, you should be able to compile the Tribe Engine
