# 62503_capitalize_tokens

## Build and install

```console
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Prep

(output wrapped btw)

```console
$ cat ../input.txt
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin vel
arcu id est tempus fermentum. Donec sodales vel magna a euismod.
Maecenas at leo ac justo accumsan eleifend. Quisque vel tempus orci,
non scelerisque nisi. Nullam hendrerit metus id fermentum
sollicitudin. Nunc sed est finibus mi consequat rhoncus vel vel
felis.
```

## Run

```console
./dist/bin/capitalize <../input.txt
```

Should output something like (again, wrapped):

```console
$ ./dist/bin/capitalize <../input.txt
Lorem Ipsum Dolor Sit Amet, Consectetur Adipiscing Elit. Proin Vel
Arcu Id Est Tempus Fermentum. Donec Sodales Vel Magna A Euismod.
Maecenas At Leo Ac Justo Accumsan Eleifend. Quisque Vel Tempus Orci,
Non Scelerisque Nisi. Nullam Hendrerit Metus Id Fermentum
Sollicitudin. Nunc Sed Est Finibus Mi Consequat Rhoncus Vel Vel
Felis.
```

