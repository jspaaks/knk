# 58819_eolconvert

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```


## Windows to Linux

```shell
$ echo -ne "dfasdf\r\ncvacv\r\n" > windows.in
$ xxd windows.in
00000000: 6466 6173 6466 0d0a 6376 6163 760d 0a    dfasdf..cvacv..
$ ./dist/bin/eolconvert --windows-to-linux windows.in linux.out
Converting Windows line endings in file 'windows.in' to Linux line ending, and saving the result as file 'linux.out'...
Done.
$ xxd linux.out
00000000: 6466 6173 6466 0a63 7661 6376 0a         dfasdf.cvacv.
```

## Linux to Windows

```shell
$ echo -ne "dfasdf\ncvacv\n" > linux.in
$ xxd linux.in
00000000: 6466 6173 6466 0a63 7661 6376 0a         dfasdf.cvacv.
$ ./dist/bin/eolconvert --linux-to-windows linux.in windows.out                                                                                                                                                                                                                                              
Converting Linux line endings in file 'linux.in' to Windows line ending, and saving the result as file 'windows.out'...
Done.
$ xxd windows.out
00000000: 6466 6173 6466 0d0a 6376 6163 760d 0a    dfasdf..cvacv..
```

