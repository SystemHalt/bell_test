CC=g++
CXXFALGS=-std=c++17 -Iinc -lPocoNet -lPocoFoundation -lPocoUtil
LDFLAGS=-L usr/lib -lPocoNet -lPocoFoundation
SRC=src/main.cpp src/Connection.cpp
OBJ=$(SRC:.cpp=.o)
EXECUTABLE=reverse_server

all: $(SRC) $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

.cpp.o:
	$(CC) $(CXXFALGS) $< -o $@
