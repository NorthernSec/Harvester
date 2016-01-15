CC = g++
FILES = src/main.cpp src/logger.cpp src/module_manager.cpp src/module_facebook.cpp src/module_google.cpp src/network.cpp src/JSON.cpp src/JSONValue.cpp
OUT_BIN = bin/harvester

build: $(FILES)
	$(CC) -o $(OUT_BIN) $(FILES) -Wall -g -lcurl -std=c++11 

clean:
	rm -f *.o core

rebuild: clean build
