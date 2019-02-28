CC = g++
CFLAGS = -c -Wall
OBJ = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
EXE = main


all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $(EXE).o InputParser.o UserManager.o

%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -f $(EXE) $(OBJ)

