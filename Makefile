SHELL = /bin/bash
CC = gcc
CFLAGS = -lstdc++ -lreadline -W

.SUFFIXS: .c .cpp
main: main.o interface.o data_structure.o
	@${CC} main.o interface.o data_structure.o ${CFLAGS} -o list
%.o: %.c
	@${CC} $< ${CFLAGS} -c
.PHONY: clean
clean:
	@rm -rf *.o
