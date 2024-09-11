# 49800_stackadt2

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
./dist/bin/demo
```

Should output something like:

```console
Program to demonstate features of the stackADT library.
 -- Created stack of capacity 3.
 -- Testing if the stack is empty...
 -- Stack is empty.
 -- Pushing '(Item) 10' onto the stack.
 -- Testing if the stack is empty...
 -- Stack is not empty.
 -- Pushing '(Item) 11' onto the stack.
 -- Testing if the stack is full...
 -- Stack is not full.
 -- Pushing '(Item) 12' onto the stack.
 -- Testing if the stack is full...
 -- Stack is full.
 -- Popping the last item of the stack...
 -- Popped item was: 12
 -- Testing if the stack is full...
 -- Stack is not full.
 -- Popping the last item of the stack...
 -- Popped item was: 11
 -- Popping the last item of the stack...
 -- Popped item was: 10
 -- Testing if the stack is empty...
 -- Stack is empty.
 -- Freed memory resources previously held by Stack instance.
```

