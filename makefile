CXX = g++
CXXFLAGS = -I . -Wall -Werror -Wextra -pedantic 

all: BIN bin/power_prf

bin/power_prf: src/main.cpp bin/sum.o
	$(CXX) $(CXXFLAGS) -o $@ $^

bin/sum.o: src/sum.cpp $(wildcard headers/*.hpp)
	$(CXX) $(CXXFLAGS) -o $@ $^

BIN:
	[ -d bin ] || mkdir -p bin

run: all
	bin/power_prf test/test2 -d

clean:
	rm bin/*
