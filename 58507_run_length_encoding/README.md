# 58507_run_length_encoding

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Prep

```shell
# write binary test data to ../input
$ echo -n -e \\x46\\x6F\\x6F\\x20\\x62\\x61\\x72\\x21\\x21\\x21\\x20\\x20\\x20\\x20\\x20 > ../input.txt
$ xxd ../input.txt
00000000: 466f 6f20 6261 7221 2121 2020 2020 20    Foo bar!!!     
```

## Run

```shell
$ ./dist/bin/rle --help
Usage:

   rle [ --encode | -e ] FILENAME     Compress the contents of FILENAME
                                      using run-length encoding and save
                                      it as a new file; the created file
                                      will be named FILENAME plus the .rle
                                      extension.

   rle [ --decode | -d ] FILENAME     Decompress the contents of FILENAME
                                      using run-length encoding and save it
                                      as a new file. FILENAME should have a
                                      .rle extension; the created file will
                                      be named FILENAME minus the extension.
$ ./dist/bin/rle --encode ../input.txt
encoding
$ xxd ../input.txt.rle
00000000: 0146 026f 0120 0162 0161 0172 0321 0520  .F.o. .b.a.r.!. 
$ ./dist/bin/rle --decode ../input.txt.rle
decoding
$ xxd ../input.txt
00000000: 466f 6f20 6261 7221 2121 2020 2020 20    Foo bar!!!     
```
