# 58819_eolconvert

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Prep

```
$ echo -ne "dfasdf\n\rcvacv\n\r" > windows.in
$ echo -ne "dfasdf\ncvacv\n" > linux.in 
$ xxd windows.in
00000000: 6466 6173 6466 0a0d 6376 6163 760a 0d    dfasdf..cvacv..
$ xxd linux.in
00000000: 6466 6173 6466 0a63 7661 6376 0a         dfasdf.cvacv.
```

## Run

```shell
$ ./dist/bin/eolconvert --windows-to-linux windows.in linux.out
Converting Windows line endings in file 'windows.in' to Linux line ending, and saving the result as file 'linux.out'...
Done.
$ xxd linux.out 
00000000: 6466 6173 6466 0a63 7661 6376 0a         dfasdf.cvacv.
```

And 

```shell
$ ./dist/bin/eolconvert --linux-to-windows linux.in windows.out
Converting Linux line endings in file 'linux.in' to Windows line ending, and saving the result as file 'windows.out'...
Done.
$ xxd windows.out                                                                                                                                                                                                                                                                                            
00000000: 6466 6173 6466 0a0d 6376 6163 760a 0d    dfasdf..cvacv..
```

