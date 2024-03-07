MLX42 is a performant, easy to use, cross-platform, minimal windowing graphics library to create graphical applications without having to work directly with the native windowing framework of the given operating system.

It provides primitive tools to draw textures onto the window as well as modifying them at runtime as they get displayed on the window.

# Features ✨

MLX42 comes with a plethora of features that make using it actually a joy instead of a chore.

## Cross-Platform 🖥️

Run it on your grandma's WindowsXP, on your uncle's debian or on a hipster's MacOS!
No matter what the platform, if MLX42 can build on it, it will run on its native windowing system. 

This allows you to work on your project no matter which machine it is on.

## Documented 📚

MLX42 cares about good documentation, every function, usage and even some internal workings are documented!
No more guessing and searching how something functions or is supposed to work.

## Performance 🚀

It is built on OpenGL and uses batched rendering to speed up the rendering process compared to other libraries.

## Open source && Community driven 🌐
This project is being actively maintained by Codam as well as students from the 42 Network. This gives students the direct opportunity to learn more about the library itself as well as fix any potential bugs instead of merely accepting them.

---

## Installation 🏗️
### General compilation

Overall the building of this project is as follows for ALL systems. As long as CMake can make sense of it.

1. [Download and build MLX42](#download-and-build---mlx42) 

In case your system doesn't have [glfw](https://github.com/glfw/glfw) installed cmake will detect this and download it for you.
You can then run `sudo make install` in the `_deps` directory of glfw. If you're using a 42 Computer (MacOS, Linux), ask your favourite sysadmin to install it.
Same goes for CMake or any other dependencies you might need for your system.

However if you can't do either CMake will still be able to fetch GLFW and build it. You can then statically link it from the `_deps` folder.

> [!NOTE]
> For Codam, GLFW is already installed on the Macs.

> [!NOTE]
> During the linking stage, the flag to link GLFW can either be: -lglfw3 or -lglfw depending on your system.

1. Compile your program with the library:
	- For: [MacOS](#for-macos)
	- For: [Linux](#for-linux)
	- For: [Windows](#for-windows)

2. Profit!

### Installing to the system

To fully build the library and install it to your system run the following command:
```bash
cmake -B build && cmake --build build --parallel --config (Debug|Release|RelWithDebInfo|MinSizeRel) --target install
```

By default windows will place the installed lib into: `C:\Program Files (x86)\mlx42` and for MacOS / Linux it will be placed into `/usr/local/lib` and `/usr/local/include` respectively.

### Unit tests
MLX42 comes with some unit tests to ensure the integrity of the library, to build them run the following command:
```sh
cmake -DBUILD_TESTS=ON -B build && cmake --build build --parallel
```

Then simply run them with:
```sh
ctest --output-on-failure --test-dir build
```

----

## Download and build - MLX42

```bash 
git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build # build here refers to the outputfolder.
cmake --build build -j4 # or do make -C build -j4
```

The output library file is called `libmlx42.a` and is located in the `build` folder that you specified.

### Available Options

You can pass build [options](./docs/index.md#available-options) to cmake, e.g: `cmake -DDEBUG=1 -DGLFW_FETCH=0...`. These will for instance let you build it in DEBUG mode or alter any sort of behaviour at build-time.

You can find an example makefile in the documentation [here](https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md).
