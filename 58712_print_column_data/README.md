# 58712_print_column_data

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Prep

```text
cat ../input
583,13.5,10/24/2005
3912,599.99,7/27/2008
```

## Run

```shell
./dist/bin/tabulate -i ../input.txt
```

Should output something like:

```text
Item          Unit           Purchase
              price          date
583           $  13.50       10/24/2005
3912          $ 599.99        7/27/2008
```
