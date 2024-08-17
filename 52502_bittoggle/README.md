# 52502_bittoggle

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
./dist/bin/program
```

should output something like:

```text
i = 255 (0b11111111)
 -- toggled bit 7
 -- i = 127 (0b01111111)

i = 127 (0b01111111)
 -- toggled bit 6
 -- i = 63 (0b00111111)

i = 63 (0b00111111)
 -- toggled bit 5
 -- i = 31 (0b00011111)

i = 31 (0b00011111)
 -- toggled bit 4
 -- i = 15 (0b00001111)

i = 15 (0b00001111)
 -- toggled bit 3
 -- i = 7 (0b00000111)

i = 7 (0b00000111)
 -- toggled bit 2
 -- i = 3 (0b00000011)

i = 3 (0b00000011)
 -- toggled bit 1
 -- i = 1 (0b00000001)

i = 1 (0b00000001)
 -- toggled bit 0
 -- i = 0 (0b00000000)

i = 0 (0b00000000)
 -- toggled bit 7
 -- i = 128 (0b10000000)


```