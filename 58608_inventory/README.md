# 58608_inventory

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
Enter one-letter operation code [dump, insert, restore, search, update, print, quit]: i
Enter part number: 1
Enter part name: one
Enter quantity on hand: 1
Enter one-letter operation code [dump, insert, restore, search, update, print, quit]: i
Enter part number: 2
Enter part name: two
Enter quantity on hand: 2
Enter one-letter operation code [dump, insert, restore, search, update, print, quit]: i
Enter part number: 3
Enter part name: three
Enter quantity on hand: 33
Enter one-letter operation code [dump, insert, restore, search, update, print, quit]: d
Dumped database contents to file 'inventory.bin'.
Enter one-letter operation code [dump, insert, restore, search, update, print, quit]: q
$ ./dist/bin/inventory                                                                                                                                                                                                                                                                                       
Enter one-letter operation code [dump, insert, restore, search, update, print, quit]: p
Part Number   Part Name                          Quantity on Hand
Enter one-letter operation code [dump, insert, restore, search, update, print, quit]: r
Restored database contents from file 'inventory.bin'.
Enter one-letter operation code [dump, insert, restore, search, update, print, quit]: p
Part Number   Part Name                          Quantity on Hand
      1       one                                1
      2       two                                2
      3       three                             33
```
