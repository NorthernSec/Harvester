CC = gcc
FILES = src/main.c src/ssl.c
OUT_BIN = bin/harvester

build: $(FILES)
	$(CC) -o $(OUT_BIN) $(FILES)

clean:
	rm -f *.o core

rebuild: clean build
