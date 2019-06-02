# Autotype

## Overview

The `autotype` class allows users to wrap all data types in a common class.
In the event of a bad conversion, the class throws a runtime exception rather than a compile time exception.
**This type is not intended for use in shared data applications.**

The autotype class is available in two libraries: a dynamic and a static library.
Both contain the same definitions, so use whichever one suits your application best.

## Class Locations

* `namespace celstd`
  * `autotype`
  * `namespace celstd::autotype_helper`
    * `bad_autotype_cast`
    * `autotype_type_info`

## Building

The binaries are not currently stored anywhere, so the libraries must be built from scratch.
If you are using CMake, you can simply call `include_subdirectory` on the autotype folder within your `CMakeLists.txt`
The cmake projects available to you are:

`autotype`

`autotype_static`

For the dynamic and static libraries, respectively.
You can also build the libraries using CMake to a separate folder.
Dynamic libraries will be available in the `lib` directory, and static libraries will be available in the `arc` directory.

Otherwise, you can build from source by setting the `include` subdirectory as an included folder in your C compiler, and build all the `.cpp` files in the `src` folder.

## Getting Started

The `autotype` class is simple to use.
Just assign any value to the autotype class and retrieve it later.
For example:

```cpp
int x = 45;
autotype sample = x;
int y = sample;

x == y; // Evaluates to true
```

```cpp
std::string x = "Hello World";
autotype sample = x;

int y = sample; // Throws bad_autotype_cast exception
```

## Core concepts

The `autotype` class works by using a generic constructor and operator to allow implicit conversion to any type.
When created, the `autotype` class stores the type of the contained data using an `autotype_type_info` object.

When the data is retrieved, the `autotype` object compares the stored type hash with the implicit conversion class.
If the hash matches, the value is converted and returned.
Otherwise, the `autotype` object throws a `bad_autotype_cast` exception.

## Further Reading

For more information and documentation, please refer to the wiki.
