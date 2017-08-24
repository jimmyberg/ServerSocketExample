CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic -pthread -lssl -lcrypto
BIN=prog

SRC=$(wildcard *.cpp) $(wildcard */*.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -pthread -o $(BIN) $^ -lssl -lcrypto

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o
	rm $(BIN)


