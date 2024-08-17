
```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
./dist/bin/program
```

should output somehting like:

```text
Different views on the same bits through type unions:
 -- EAX = 0xFEDCBA98
 --  AX =     0xBA98
 --  AH =     0xBA
 --  AL =       0x98

 -- EBX = 0x76543210
 --  BX =     0x3210
 --  BH =     0x32
 --  BL =       0x10

 -- ECX = 0x01234567
 --  CX =     0x4567
 --  CH =     0x45
 --  CL =       0x67

 -- EDX = 0x89ABCDEF
 --  DX =     0xCDEF
 --  DH =     0xCD
 --  DL =       0xEF

```