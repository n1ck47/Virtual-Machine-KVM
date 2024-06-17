# CS695 Assignment 2

# Part 1

simple-kvm is a very simple example program to demonstrate the use of the KVM API provided by the Linux kernel. Tested in Intel processors with the VMX hardware virtualization extensions and AMD processors with AMD-V hardware virtualization extensions.

The part1a.pdf shows the flow the execution of the VM in the long mode of operation. It also decribes the various KVM api calls.

## How to run

````bash
make 

./simple-kvm -l
````

Performing a ```make clean``` will remove the executable and the object 

# Part 2

matrix is a example program to demonstrate running of two VM using KVM API. Tested in Intel processors with the VMX hardware virtualization extensions and AMD processors with AMD-V hardware virtualization extensions.

## How to run
````bash
make
````

To run 2.a
````bash
./matrix-a
````

To run 2.b
````bash
./matrix-b
````

To run 2.c
````bash
./matrix
````

Performing a ```make clean``` will remove the executable and the object files. You should perform this while updating the code and recompiling.
