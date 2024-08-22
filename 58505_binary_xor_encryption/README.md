# 58505_binary_xor_encryption

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
$ cat ../plain.txt
Trust not him with your secrets, who, when left
alone in your room, turns over your papers.
            --Johann Kaspar Lavater (1741-1801)
$ xxd ../plain.txt
00000000: 5472 7573 7420 6e6f 7420 6869 6d20 7769  Trust not him wi
00000010: 7468 2079 6f75 7220 7365 6372 6574 732c  th your secrets,
00000020: 2077 686f 2c20 7768 656e 206c 6566 740a   who, when left.
00000030: 616c 6f6e 6520 696e 2079 6f75 7220 726f  alone in your ro
00000040: 6f6d 2c20 7475 726e 7320 6f76 6572 2079  om, turns over y
00000050: 6f75 7220 7061 7065 7273 2e0a 2020 2020  our papers..    
00000060: 2020 2020 2020 2020 2d2d 4a6f 6861 6e6e          --Johann
00000070: 204b 6173 7061 7220 4c61 7661 7465 7220   Kaspar Lavater 
00000080: 2831 3734 312d 3138 3031 290a            (1741-1801).
```

## Run

```shell
$ ./dist/bin/encrypt ../plain.txt ../cypher.txt \&
$ xxd ../cypher.txt
00000000: 7254 5355 5206 4849 5206 4e4f 4b06 514f  rTSUR.HIR.NOK.QO
00000010: 524e 065f 4953 5406 5543 4554 4352 550a  RN._IST.UCETCRU.
00000020: 0651 4e49 0a06 514e 4348 064a 4340 522c  .QNI..QNCH.JC@R,
00000030: 474a 4948 4306 4f48 065f 4953 5406 5449  GJIHC.OH._IST.TI
00000040: 494b 0a06 5253 5448 5506 4950 4354 065f  IK..RSTHU.IPCT._
00000050: 4953 5406 5647 5643 5455 082c 0606 0606  IST.VGVCTU.,....
00000060: 0606 0606 0606 0606 0b0b 6c49 4e47 4848  ..........lINGHH
00000070: 066d 4755 5647 5406 6a47 5047 5243 5406  .mGUVGT.jGPGRCT.
00000080: 0e17 1112 170b 171e 1617 0f2c            ...........,
$ ./dist/bin/encrypt ../cypher.txt ../decrypt.txt \&
$ xxd ../decrypt.txt
00000000: 5472 7573 7420 6e6f 7420 6869 6d20 7769  Trust not him wi
00000010: 7468 2079 6f75 7220 7365 6372 6574 732c  th your secrets,
00000020: 2077 686f 2c20 7768 656e 206c 6566 740a   who, when left.
00000030: 616c 6f6e 6520 696e 2079 6f75 7220 726f  alone in your ro
00000040: 6f6d 2c20 7475 726e 7320 6f76 6572 2079  om, turns over y
00000050: 6f75 7220 7061 7065 7273 2e0a 2020 2020  our papers..    
00000060: 2020 2020 2020 2020 2d2d 4a6f 6861 6e6e          --Johann
00000070: 204b 6173 7061 7220 4c61 7661 7465 7220   Kaspar Lavater 
00000080: 2831 3734 312d 3138 3031 290a            (1741-1801).
```
