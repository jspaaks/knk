# 62607_counting_sentences

## Build and install

```console
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Prep

```console
$ echo -n "Hello. How are you?
> I haven't seen you in forever! We should get together sometime!
> -- Alright, gotta go.
> Until next time." > ../input.txt
```

## Run

```console
$ ./dist/bin/count <../input.txt
```

Should output something like:

```console
Counted 6 sentences in text provided on STDIN.
```
