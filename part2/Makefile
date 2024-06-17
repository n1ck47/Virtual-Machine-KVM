all: matrix guest1.bin guest2.bin matrix-b guest1-b.bin guest2-b.bin matrix-a guest1-a.bin guest2-a.bin

# part c
matrix:
	gcc matrix.c -o matrix -lpthread

guest1.bin: guest1.o
	ld -m elf_i386 --oformat binary -N -e _start -Ttext 0x10000 -o guest1.bin guest1.o

guest2.bin: guest2.o
	ld -m elf_i386 --oformat binary -N -e _start -Ttext 0x10000 -o guest2.bin guest2.o

guest1.o: guest1.s
	as -32 guest1.s -o guest1.o

guest2.o: guest2.s
	as -32 guest2.s -o guest2.o

# part b
matrix-b:
	gcc matrix-b.c -o matrix-b -lpthread

guest1-b.bin: guest1-b.o
	ld -m elf_i386 --oformat binary -N -e _start -Ttext 0x10000 -o guest1-b.bin guest1-b.o

guest2-b.bin: guest2-b.o
	ld -m elf_i386 --oformat binary -N -e _start -Ttext 0x10000 -o guest2-b.bin guest2-b.o

guest1-b.o: guest1-b.s
	as -32 guest1-b.s -o guest1-b.o

guest2-b.o: guest2-b.s
	as -32 guest2-b.s -o guest2-b.o

# part a
matrix-a:
	gcc matrix-a.c -o matrix-a -lpthread

guest1-a.bin: guest1-a.o
	ld -m elf_i386 --oformat binary -N -e _start -Ttext 0x10000 -o guest1-a.bin guest1-a.o

guest2-a.bin: guest2-a.o
	ld -m elf_i386 --oformat binary -N -e _start -Ttext 0x10000 -o guest2-a.bin guest2-a.o

guest1-a.o: guest1-a.s
	as -32 guest1-a.s -o guest1-a.o

guest2-a.o: guest2-a.s
	as -32 guest2-a.s -o guest2-a.o

.PHONY: clean
clean:
	$(RM) matrix guest1.bin guest1.o \
		guest2.bin guest2.o
	$(RM) matrix-b guest1-b.bin guest1-b.o \
		guest2-b.bin guest2-b.o
	$(RM) matrix-a guest1-a.bin guest1-a.o \
		guest2-a.bin guest2-a.o
	
