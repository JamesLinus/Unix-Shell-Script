CC = gcc
CFLAGS = -Wall -g
OBJECTS = cli.o
EXES = cli
FILES = *.c src/*.c headers/*.h

all: $(EXES)

cli: $(OBJECTS)
		$(CC) $(CFLAGS) -o cli $(FILES)

clean:
		@echo -n Cleaning...
		@rm $(OBJECTS) *~ $(EXES) 2>/dev/null || true
		@echo done 