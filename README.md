# Pathfinder
Pathfinder is a CLI tool that finds all the shortest paths between nodes.

## About Pathfinder
This projects demonstrates a pathfinding application that:
* Reads from a specified file (see tests folder)
* Creates a weighted graph from the input
* Runs it through a pathfinding algorithm (Dijkstra's in this case)
* Displays the results in the console
* Handles errors throughout app's lifecycle.

## Built with
* **C**
* **Make**
* **libmx** (custom library)
* **Valgrind**

## Getting started
These instructions will help you configure and compile this project to run it on your machine.

### Prerequisites
Before trying to compile the application, make sure you have clang compiler and Make installed on your system.

* On Linux (Ubuntu):
```
sudo apt install build-essential clang
```

* On macOS:
```
xcode-select --install
```

### Important
**You can skip this section if you are not using Linux.**

Linux and macOS use a different header and function in order to get the size of allocated memory.

To successfully compile the program on Linux, navigate to `libmx/inc/libmx.h`. Open the header file and replace `#include <malloc/malloc.h>` with `#include <malloc.h>`. Then go to libmx/src/realloc.c and replace `malloc_size` function with `malloc_usable_size`.

### Installation
Once cloned the repository, navigate to pathfinder root directory and simply run 'make' command:
```
make
```

The application should now be ready to run.

## Usage

Run the application with `./pathfinder` command. This should result with usage output.

Specify the file you want to read in order to compute the paths. You can create your own files, or use test files from 'tests' folder:
```
./pathfinder tests/medium.txt
```

**Output Example:**

<img width="1132" alt="image" src="https://github.com/user-attachments/assets/3ec915fc-241f-4b61-b2f0-0024abea75bc" />
