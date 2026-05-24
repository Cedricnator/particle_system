# Particle System

This is a simulation of a particle system made with `C++`.
The requiriements of this program are simple, the program will be display a window in your computer, then in the window are generated random circles(100) that have gravity.
If you move the window, the circles will be move with the window, making the same movement of real life particles in a box.

## Requiriements

For run this program, you need to following requiriements. If you don't have them, you cannot run this project.

1. Raylib: You need to install `Raylib` in your operating system, this library comes with helpers for rendering elements on the screen.
2. C++ Compiler: You need the `C++` compiler, like `g++`, because the compiler needs to undestand the `C++` standart libraries.
3. Make: This is a utility for compiling this program, you only type in your shell: `make` and this will generate a `main` file, this file is a execute binary. This requirement is optional, you can enter the full command for generate that binary.

## Step by step

To execute this project, you need to follow the following steps:

### Compile the project

For this, you can use `make` or enter the full command. For example, with make the command is like this:

```bash
make
```

And for the full command is like this, for `Linux`:

```bash
 g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o main
```

### Run the program

To execute this program, you only need to do is running the `binary`.

```bash
./main
```

If you have problems with the OS permissions, you can execute the folloing command to fix this:

```bash
chmod +x main
```
