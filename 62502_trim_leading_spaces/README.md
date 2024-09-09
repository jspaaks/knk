# 62502_trim_leading_spaces

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
$ cat ../input.txt                                                                                                                                
 __   __



        \ \_/ /
   (='.'=)


               (")_(")


(Adapted from https://en.wikipedia.org/wiki/ASCII_art)

```

## Run

```console
./dist/bin/trimlead <../input.txt
```

Should output something like:

```console
__   __
\ \_/ /
(='.'=)
(")_(")
(Adapted from https://en.wikipedia.org/wiki/ASCII_art)
```

