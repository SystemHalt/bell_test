CC=g++
CXXFALGS=-c -std=c++17 -Iinc
LIBS=-lPocoNet -lPocoFoundation
SRC_DIR=src
BUILD_DIR=build
OBJ_DIR=$(BUILD_DIR)/obj
OUT_DIR=$(BUILD_DIR)/out
EXECUTABLE=$(OUT_DIR)/reverse_server

all:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OUT_DIR)
	$(CC) $(CXXFALGS) $(SRC_DIR)/Connection.cpp -o $(OBJ_DIR)/Connection.o
	$(CC) $(CXXFALGS) $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o
	$(CC) $(OBJ_DIR)/Connection.o $(OBJ_DIR)/main.o -o $(EXECUTABLE) $(LIBS)

clean:
	rm -rf $(BUILD_DIR)