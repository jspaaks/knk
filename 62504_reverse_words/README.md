# 62504_reverse_words

## Build and install

```console
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Run

```console
$ ./dist/bin/reverse --help
Usage: reverse
    Prompt the user for a sequence of words, then print them in reverse order.

$ ./dist/bin/reverse
Program to print words in reverse order.
Please enter a sequence of words separated by a single whitespace: 
Sequence has 0 words.

$ ./dist/bin/reverse                                                                                                                              
Program to print words in reverse order.
Please enter a sequence of words separated by a single whitespace: The quick brown fox jumps over the lazy dog
Sequence has 9 words. In reversed order: 
dog lazy the over jumps fox brown quick The
```

