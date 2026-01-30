CC=gcc
CFLAGS=-c -Wall -pedantic
INC=./inc
SRC=./src
BLD=./build
EXE=MCSlime

all: $(BLD)/main.o $(BLD)/JavaRNG.o $(BLD)/SlimeChunk.o
	$(CC) $^ -o $(BLD)/$(EXE)

$(BLD)/main.o: $(SRC)/main.c $(INC)/SlimeChunk.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC)

$(BLD)/JavaRNG.o: $(SRC)/JavaRNG.c $(INC)/JavaRNG.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC)

$(BLD)/SlimeChunk.o: $(SRC)/SlimeChunk.c $(INC)/SlimeChunk.h $(INC)/JavaRNG.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC)


.PHONY: clean
clean:
	rm ./build/*.o
	rm ./build/$(EXE)

.PHONY: run
run:
	$(BLD)/$(EXE)
