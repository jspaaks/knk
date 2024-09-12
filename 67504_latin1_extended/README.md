# 67504_latin1_extended

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
./dist/bin/demo
Program to demonstrate printing code points beyond
ASCII but still within Latin-1 Extended.
 -- d�j� vu
 -- C�te d'Azur
 -- cr�me br�l�e*
 -- cr�me fra�che*
 -- Fahrvergn�gen
 -- t�te � t�te
Used code page from https://en.wikipedia.org/wiki/Latin-1_Supplement to encode this.
* Required string splitting.
```

Output is messed up because terminal expects UTF-8 encoding. So pipe to file instead:

```console
$ ./dist/bin/demo > file.txt
$ xxd file.txt
$ xxd file.txt 
00000000: 5072 6f67 7261 6d20 746f 2064 656d 6f6e  Program to demon
00000010: 7374 7261 7465 2070 7269 6e74 696e 6720  strate printing 
00000020: 636f 6465 2070 6f69 6e74 7320 6265 796f  code points beyo
00000030: 6e64 0a41 5343 4949 2062 7574 2073 7469  nd.ASCII but sti
00000040: 6c6c 2077 6974 6869 6e20 4c61 7469 6e2d  ll within Latin-
00000050: 3120 4578 7465 6e64 6564 2e0a 202d 2d20  1 Extended.. -- 
00000060: 64e9 6ae0 2076 750a 202d 2d20 43f4 7465  d.j. vu. -- C.te
00000070: 2064 2741 7a75 720a 202d 2d20 6372 e86d   d'Azur. -- cr.m
00000080: 6520 6272 fb6c e965 2a0a 202d 2d20 6372  e br.l.e*. -- cr
00000090: e86d 6520 6672 61ee 6368 652a 0a20 2d2d  .me fra.che*. --
000000a0: 2046 6168 7276 6572 676e fc67 656e 0a20   Fahrvergn.gen. 
000000b0: 2d2d 2074 e874 6520 e120 74e8 7465 0a55  -- t.te . t.te.U
000000c0: 7365 6420 636f 6465 2070 6167 6520 6672  sed code page fr
000000d0: 6f6d 2068 7474 7073 3a2f 2f65 6e2e 7769  om https://en.wi
000000e0: 6b69 7065 6469 612e 6f72 672f 7769 6b69  kipedia.org/wiki
000000f0: 2f4c 6174 696e 2d31 5f53 7570 706c 656d  /Latin-1_Supplem
00000100: 656e 7420 746f 2065 6e63 6f64 6520 7468  ent to encode th
00000110: 6973 2e0a 2a20 5265 7175 6972 6564 2073  is..* Required s
00000120: 7472 696e 6720 7370 6c69 7474 696e 672e  tring splitting.
00000130: 0a
```

Now open up in a text editor that understands ISO 9959-1, e.g. VSCode.
Should show:

```text
Program to demonstrate printing code points beyond
ASCII but still within Latin-1 Extended.
 -- déjà vu
 -- Côte d'Azur
 -- crème brûlée*
 -- crème fraîche*
 -- Fahrvergnügen
 -- tète á tète
Used code page from https://en.wikipedia.org/wiki/Latin-1_Supplement to encode this.
* Required string splitting.
```

