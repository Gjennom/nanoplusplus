CC = g++ -std=c++17
LDFLAGS = -lraylib

TARGET = nano++.exe
SRC = nano++.cpp nano++_functions.cpp
OBJ = $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.cpp nano++.h
	$(CC) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
