<h1 align="center">
  <br>
  <a href="#"><img src="https://i.ibb.co/ZgGrJCW/df7cd7d0-25d8-4bf1-a430-841dbc475315-200x200.png" alt="libCFGUtils" width="200"></a>
  <br>
  libCFGUtils
  <br>
</h1>

<h4 align="center">Utility functions over LLVM IR</h4>


## Table of Contents

- [Getting Started](#getting-started)
  - [Building from source](#build-from-source)
  - [Using with opt](#using-with-opt)
- [Utilities](#utilities)
  - [InstNamer](#instnamer)
  - [SkipFunction](#skipfunction)
  - [GetPred](#getpred)

## Getting Started

### Building from source
```sh
$ git clone this_repository.git
$ cd this_repository
$ mkdir build; cd build
$ cmake .. && make
$ make install
```
### Using with opt
* Path to shared libary and headers should be searchable by the compiler
* In your LLVM IR pass:
  * Include the header file, ```CFGUtils/CFGUtils.h```
  * Use namespace ```CFGUtils```
* Load libAliasBench.so before your pass's shared library
  * ``` opt -load /usr/local/lib/libCFGUtils.so -load yourPass.so ... ```

## Utilities

### InstNamer 
Motivated from LLVM's InstNamer pass for naming unnamed temporaries

### SkipFunction
Skip functions which does not affect the analysis

### GetPred
Returns predecessors for any LLVM instruction
