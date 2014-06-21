CC = gcc

CFLAGS = -ansi -pedantic -Wall

DBGFLAGS = -ggdb3

WARNINGS = -Wall -Wextra -Wfloat-equal -Wundef -Wshadow -Wpointer-arith \
        -Wcast-align -Wstrict-overflow=5 -Wwrite-strings \
        -Waggregate-return -Wcast-qual -Wswitch-default -Wswitch-enum \
        -Wconversion -Wunreachable-code -Wformat=2 -Winit-self \
        -Wuninitialized -Werror-implicit-function-declaration

EXECUTABLE = p27

all: $(EXECUTABLE)

$(EXECUTABLE): p27.c
	$(CC) $(CFLAGS) $(DBGFLAGS) $(WARNINGS) $^ -o $@

clean:
	rm -f a.out
	rm -f *~
	rm -f *.o
	rm -f *.gch
	rm -f $(EXECUTABLE)
