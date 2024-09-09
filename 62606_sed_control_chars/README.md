# 62606_sed_control_chars

## Build and install

```console
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Prep 

```console
$ echo -ne "a\tb\tc\nd,e,f\v\n" > ../input.txt
$ xxd ../input.txt                                                                                                                                
00000000: 6109 6209 630a 642c 652c 660b 0a         a.b.c.d,e,f..
```

## Run

```console
$ ./dist/bin/showctrlchrs --help
Usage: showctrlchrs
   Copy STDIN to STDOUT while replacing any control
   characters except '\n' with '?'.

$ ./dist/bin/showctrlchrs <../input.txt                                                                                                           
a?b?c
d,e,f?
```

