ARGS			=
EXECUTABLE		=main
CC				=gcc
CFLAGS			=-Wall --pedantic -std=c2x -g3
#CFLAGS			=-Wall -std=c2x -g3
LDFLAGS			=
SOURCES			=$(wildcard *.c)
HEADERS			=$(wildcard *.h)
OBJECTS			=$(SOURCES:.c=.o)

all: $(EXECUTABLE)
	./$(EXECUTABLE) $(ARGS)

build: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(EXECUTABLE)

.PHONY: clean
clean:
	-rm $(OBJECTS)