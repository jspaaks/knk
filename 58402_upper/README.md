# 58402_upper

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Run

```shell
cat ../input.txt
$ cat ../input.txt
sdfas 431245  qerfasd 
fasd f sd qer`31
adf qe rt  er13  1345`145`5 
`345r
`245r4t134f      wef     rg     3r
g   3r4g
$ ./dist/bin/upper ../input.txt
```

Should output something like:

```text
SDFAS 431245  QERFASD 
FASD F SD QER`31
ADF QE RT  ER13  1345`145`5 
`345R
`245R4T134F      WEF     RG     3R
G   3R4G
Done.
```
