# 67606_trigraphs

Bleeding trigraphs why?!

## Build and install

```console
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
```

## Run

```console
$ ./dist/bin/trigraphs <../plain.txt
rTSUR HIR NOK QORN _IST UCETCRU, QNI, QNCH JC@R
GJIHC OH _IST TIIK, RSTHU IPCT _IST VGVCTU.
            --lINGHH mGUVGT jGPGRCT (1741-1801)
```

