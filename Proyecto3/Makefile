all: copy lru

copy:
	cp alloc.c /usr/src/minix/servers/vm/
	cp dmp.c /usr/src/minix/servers/is/dmp.c
	cp dmp_pm.c /usr/src/minix/servers/is/dmp_vm.c

lru:
	clang -o lru.o lru.c