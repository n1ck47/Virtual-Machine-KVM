# CS695 Assignment 2 - Part 1

simple-kvm is a very simple example program to demonstrate the use of the KVM API provided by the Linux kernel. Tested in Intel processors with the VMX hardware virtualization extensions and AMD processors with AMD-V hardware virtualization extensions.

## How to run

````bash
make 

./simple-kvm -l
````

Performing a ```make clean``` will remove the executable and the object 