CC=gcc
CFLAGS=-c -Wall -pedantic
INC=./inc
SRC=./src
BLD=./build
EXE=MCSlime

all: $(BLD)/main.o $(BLD)/Arguments.o $(BLD)/JavaRNG.o $(BLD)/SlimeChunk.o $(BLD)/TermColors.o $(BLD)/TermMenu.o
	$(CC) $^ -o $(BLD)/$(EXE)

$(BLD)/main.o: $(SRC)/main.c $(INC)/Arguments.h $(INC)/TermMenu.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC)

$(BLD)/Arguments.o: $(SRC)/Arguments.c $(INC)/Arguments.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC)

$(BLD)/JavaRNG.o: $(SRC)/JavaRNG.c $(INC)/JavaRNG.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC)

$(BLD)/SlimeChunk.o: $(SRC)/SlimeChunk.c $(INC)/SlimeChunk.h $(INC)/JavaRNG.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC)

$(BLD)/TermColors.o: $(SRC)/TermColors.c $(INC)/TermColors.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC)

$(BLD)/TermMenu.o: $(SRC)/TermMenu.c $(INC)/TermMenu.h
	$(CC) $(CFLAGS) $< -o $@ -I$(INC)


.PHONY: clean
clean:
	rm ./build/*.o
	rm ./build/$(EXE)

.PHONY: run
run:
	$(BLD)/$(EXE)
