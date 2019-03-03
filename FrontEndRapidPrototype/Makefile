CC = g++
CFLAGS = -c -Wall -Wextra
OBJ = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
EXE = main


all: $(OBJ) $(EXE)

$(EXE): InputParser.o UserManager.o User.o
	$(CC) -o $@ $(EXE).o $^

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -f $(EXE) $(OBJ)

