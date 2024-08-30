# 58715_justify

## Build and install

```shell
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```

## Prep

Some text from the interwebs which has some long lines:

```
cat ../input-ascii.txt
In the interview, Harris explained how her positions on issues including fracking and border security have evolved since she first ran for the Democratic presidential nomination in 2019 - and offered a preview of how she's going to explain those evolutions to voters when they come up in her debate with former President Donald Trump and at other moments as the race moves forward.

"My values have not changed," she said.

She also sought to frame the 2024 race as one that offers the American people "a new way forward" after a political decade in which Trump --in office or out-- was a central figure.

Democrats have framed Harris' 2024 campaign as one of joy --a turning of the page from a former president who has cast his political rivals, the media and others as enemies and frequently tapped into dark themes with dire warnings about the nation's future. That approach will soon face its biggest test yet, with Harris and Trump both preparing for their September 10 debate on ABC.
```

## Run

```shell
./dist/bin/justify -i ../input-ascii.txt -o output.txt -c 47
```

Should output something like:

```text
 -- Opened file '../input-ascii.txt' for reading...
 -- Opened file 'output.txt' for writing...
 -- Closed file '../input-ascii.txt'.
 -- Closed file 'output.txt'.
```

And the contents of `output.txt`:

```text
$ cat output.txt
In the  interview,  Harris  explained  how  her
positions  on  issues  including  fracking  and
border  security have  evolved since she  first
ran for  the Democratic presidential nomination
in 2019 -  and offered  a preview of  how she's
going  to explain those  evolutions  to  voters
when they come up  in  her  debate with  former
President Donald Trump and at other moments  as
the  race  moves  forward. "My values  have not
changed,"  she said.  She also sought  to frame
the 2024 race  as one that offers the  American
people  "a  new  way forward" after a political
decade in which Trump  --in office or out-- was
a central figure. Democrats have framed Harris'
2024 campaign as one of joy  --a turning of the
page from  a  former president who has cast his
political  rivals,  the  media  and  others  as
enemies and frequently tapped  into dark themes
with dire  warnings  about the nation's future.
That  approach will soon face its biggest  test
yet, with Harris and  Trump both preparing  for
their September 10 debate on ABC.
```
