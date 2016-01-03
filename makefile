CC = g++
FILES = src/main.cpp src/logger.cpp src/module_manager.cpp src/module_facebook.cpp
OUT_BIN = bin/harvester

build: $(FILES)
	$(CC) -o $(OUT_BIN) $(FILES) -std=c++11 

clean:
	rm -f *.o core

rebuild: clean build
