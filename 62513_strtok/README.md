# 62513_strtok

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
echo -ne "The quick brown fox jumps over the lazy dog." > ../input.txt
```

## Run

```shell
./dist/bin/countwords <../input.txt
```

Should output something like:

```text
Sentence: 'The quick brown fox jumps over the lazy dog.'.
Counted 9 words.
```

