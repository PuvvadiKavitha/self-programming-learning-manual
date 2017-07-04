Mobj = main.o fun1.o fun2.o
#Mobj := main.o fun1.o fun2.o
CFLAGS = -g -c
CC = gcc

hello: $(Mobj)
ifeq ($(CC),gcc)
	@$(CC) $^ -o $@
else
	$(CC) $^ -o hello2
endif	

main.o: main.c
	$(CC) $(CFLAGS) main.c

fun1.o: fun1.c
	gcc -c fun1.c

fun2.o: fun2.c
	gcc -c fun2.c

.PHONY: clean
clean:
	rm $(Mobj) hello

.PHONY: install
install:
	cp hello /usr/local/hello

.PHONY: uninstall
uninstall:
	rm /usr/local/hello




