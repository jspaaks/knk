# 43400_inventory

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Run

```text
$ ./dist/bin/inventory
Enter operation code (dump, insert, restore, search, update, print, quit): i
 -- Enter part number: 234
 -- Enter part name: sdfedff
 -- Enter quantity on hand: 4343

Enter operation code (dump, insert, restore, search, update, print, quit): i
 -- Enter part number: 12213
 -- Enter part name: sdfvgefr
 -- Enter quantity on hand: 656

Enter operation code (dump, insert, restore, search, update, print, quit): i
 -- Enter part number: 1
 -- Enter part name: asd
 -- Enter quantity on hand: 213432   

Enter operation code (dump, insert, restore, search, update, print, quit): p
 -- Part number   Part name                   Quantity on hand
 --       1       asd                           213432
 --     234       sdfedff                         4343
 --   12213       sdfvgefr                         656

Enter operation code (dump, insert, restore, search, update, print, quit): d
 -- Dumping...
 -- Done.

Enter operation code (dump, insert, restore, search, update, print, quit): q
 -- Quitting.
$ ./dist/bin/inventory
Enter operation code (dump, insert, restore, search, update, print, quit): p
 -- <Empty>

Enter operation code (dump, insert, restore, search, update, print, quit): r
 -- Restoring...
 -- Done.

Enter operation code (dump, insert, restore, search, update, print, quit): p
 -- Part number   Part name                   Quantity on hand
 --       1       asd                           213432
 --     234       sdfedff                         4343
 --   12213       sdfvgefr                         656
```

