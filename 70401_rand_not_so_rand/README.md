# 70401_rand_not_so_rand

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
$ ./dist/bin/demo --help
Usage: demo
   Demonstrate different patterns in usage of rand function (on some systems).

$ ./dist/bin/demo
Method 1: Printing 10 x 100 values of rand()'s least significant bit (x means 1, ' ' means 0):

   x x    x xx   x   x x x    x  xx        xx xx xx  xx  xx   x x xx xxxxx    x x   xx xxx xxxx x x 
  xx x  xx x  xxxxx xxx  xxxx xxx xx xxx x  xx  xxx     xxxx x xxx x xxx xxxxxx     x     x x x xx  
 xx   xx  x xxx  x  x    xxx xx     xx xxxx x  x xxxxx x x         xx     xx x   x x    xx xx xx xxx
 xx x x  x         xx    x  xxxx  x x  xx xxxxxx xxxxx xx x x xx  xx x x   xxx x xxxxx  xx  xxxxxxxx
 x  x xxx  xxx     xx x xxx   x  xxxx    xx  x xxx  x  xx xx xx     x  xx x x xxxxx x x  xx  xx xx  
xx xxxx x x xxxxx xxxxxx   xx  xx   xxxxx x x x xxx  x  x xx x  x  xxx   x x   xxxxx xx x x  x xx   
      x  xxxx  x xxx  x xxx         xx xxxx  xx xxxxxxxx  x    x  xx  xxx xxx x xxxx    xxxxxx    x 
  xx  x     x xx x x xx  x  xx x xx x    x  xxxx xx    xx xx    xx xxxx  x x x  xx xxx xx  x  xx   x
xxxx x  x    xxx   x  x x xx   xx   x   xx x     xx x   xxxxx xx xxx x x        x  x  xx xxxx  xxx x
x  xx  xx     xxxx x x xxx x   xxxx xxx xxx   xxxx xx   x x x x x   xxxxx xx    x x   x    x xxx x x

Method 2: Printing 10 x 100 values of rand()'s least significant bit (x means 1, ' ' means 0):

 xxx  x      xxxxx     x x xxx xx xx   x     x x xxxx  x xxxx   x     xxx  x x x   xxxxx   x x xx x 
 x   xx     x x x   x  x  xx xxx  x xxxx xxx xx  x x  x    xx x  xxx  x   x  x  x x x x xxx x x   x 
x xxxxxxx   x x     x xxx xx xxx xx   xx   x   x xx x   xxxxxxxxx  xx x       x x xxxxx xx  xx     x
      x x x xx   xxxxx xx  xx xx x xxx   xxx x xxx x   xx x x  xx xx x   xxxxx  xx x  xxx   x  xxx x
  xx xx x       xx    xx x xxxx xx   x   xx  xxxxx x x  xx   xx  x x x x xx xx   x    x  x  x   x x 
x x x xxxxx x xxxx xxxx xx       x    x  xxxx x xxx   xx  x  x xxxxxx x  xxxx  xxx x x  x x   xxx  x
x x xxxxx xx xx x x  xxxx  xxxxx xx xxx xx x   x   x x x  xx x   x xx   xx  x xxx xxxxxx  x  xx x   
xx   xxxxxxxxx   x x x  xxx x x x xxx xxxx x x xx  xx  x  xx x xxxx  xx x x xx  xx xxxx x xxx xxxxx 
 x     xx  xxxxx  xxxxxx x     x xx x  xxx      x       xx xxx     x x x x    xxx  x   xxxxx xx     
 xx xxxx x  xx xx xxx     x  x    xx xxx  x xx xxx x x xxxx   xxx xx   x xx   x       xxxx x xxx  x
```

