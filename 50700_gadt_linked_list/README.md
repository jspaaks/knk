[![Copier](https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/copier-org/copier/master/img/badge/badge-grayscale-inverted-border-orange.json)](https://github.com/copier-org/copier)

# 50700_gadt_llist

## CMake

The project has been initialized with a [CMakeLists.txt](CMakeLists.txt)-based
configuration for building with CMake:

```shell
# change into the build directory
cd build/cmake

# generate the build files
cmake ../..

# build the project
cmake --build .

# install the project to <repo>/build/cmake/dist
cmake --install .

# run the program to see if it works
./dist/bin/demo
```

Should output something like:

```text
Creating an instance of LinkedList of int
and adding some items to it:
 -- LinkedList[0] = {}
 -- LinkedList[1] = {102}
 -- LinkedList[2] = {100, 102}
 -- LinkedList[3] = {100, 102, 103}
 -- LinkedList[4] = {100, 101, 102, 103}
Creating an instance of LinkedList of float
and adding some items to it:
 -- []
 -- [202.00]
 -- [200.00, 202.00]
 -- [200.00, 202.00, 203.00]
 -- [200.00, 201.00, 202.00, 203.00]
```

## Testing

The tests require that [Criterion](https://github.com/Snaipe/Criterion) is installed on the system, e.g. with

```shell
sudo apt install libcriterion-dev
```

Run the tests with

```shell
./dist/bin/test_llist -j1 --verbose
```
## Code::Blocks

Use [Code::Blocks IDE](https://www.codeblocks.org/) to open [.codeblocks/project.cbp](.codeblocks/project.cbp). 

## `clang-format`

The file `.clang-format` contains an initial configuration for (automatic) formatting with [clang-format](https://clang.llvm.org/docs/ClangFormat.html). Run the formatter with e.g.:

```shell
# dry run on main.c
clang-format -Werror --dry-run main.c

# format in place all *.c and *.h files under ./src
clang-format -i `find ./src -type f -name '*.[c|h]'`
```

## Acknowledgements

_This project was generated using [Copier](https://pypi.org/project/copier) and [copier-template-for-c-projects](https://github.com/jspaaks/copier-template-for-c-projects)._
