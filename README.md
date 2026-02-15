# MC Slime
A tool for finding slime chunks in Minecraft.

## About
This project is intended to provide an accurate, high-performance program that can find slime chunks in Minecraft. Currently, the project is relatively bare bones, but the goal is to expand it to allow for things such as finding groups of chunks in a specific pattern and parallel support for faster generation. Additionally, a basic console UI would be nice to have at some point.

## Compiling
This program uses CMake for building. Building the project simply requires clone the repo and compiling the code.

```
git clone https://github.com/wheeler-cs/MCSlime
cd MCSlime
mkdir build
cd build
cmake ..
cmake --build .
```

The resulting program will be name `MCSlime` by default.

No external libraries are used, and all of the logic, including RNG algorithms, have been reimplemented in C.

## Accuracy
Accuracy of this tool is not guaranteed. While an explicit goal of the project is to have a slime chunk generator with one-to-one accuracy with the Java implementation, the algorithms used by Minecraft rely on integer overflow. The `-fwrapv` argument is supplied when compiling the program in an effort to mimic this behavior, but signed integer underflow and overflow is still technically undefined behavior in C.

## Documentation
Documentation for the code is currently provided in the form of Doxygen-format docstrings. The docstring for a given function can be found in the corresponding `.h` file in the [inc](./inc/) directory.
