CC = g++
CFLAGS = -Wall -Wextra -std=c++1z
OBJ = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
EXE = main


all: $(OBJ) $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $@ $^

%.o: %.cpp %.h
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	rm -f $(EXE) $(OBJ)

