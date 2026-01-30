# MC Slime
A tool for finding slime chunks in Minecraft.

## About
This project is intended to provide an accurate, high-performance program that can find slime chunks in Minecraft. Currently, the project is relatively bare bones, but the goal is to expand it to allow for things such as finding groups of chunks in a specific pattern and parallel support for faster generation. Additionally, a basic console UI would be nice to have at some point.

## Compiling
This program uses GNUMake for building. Building is as simple as cloning the repository, making a build directory, and typing `make`.

```
git clone https://github.com/wheeler-cs/MCSlime
cd MCSlime
mkdir build
make
```

No external libraries are used, and all of the logic, including RNG algorithms, have been reimplemented in C.
