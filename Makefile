# Innspired by example semestral project https://gitlab.fit.cvut.cz/bernhdav/pa2-bomb-tag/blob/master/Makefile

CXX=g++
CXXFLAGS = -Wall -pedantic -std=c++17 -g
LIBRARIES = -lstdc++fs

HEADERS = $(wildcard src/*.h)
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=obj/%.o)
TESTS = $(wildcard tests/*.test.cpp)
username = nguyehu7

all: compile doc

compile: $(username)

run: compile
	./$(username)

nguyehu7: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^  $(LIBRARIES)

obj/%.o: src/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

debug/%.test: tests/%.test.cpp $(filter-out obj/main.o, $(OBJECTS))
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $< $(filter-out obj/main.o, $(OBJECTS))  $(LIBRARIES)

test: $(TESTS:tests/%.test.cpp=debug/%.test)
	./tests/script.sh


doc: $(HEADERS) Doxyfile README.md
	doxygen

clean:
	-rm -rf obj/
	-rm $(username)
	-rm -rf doc/
	-rm -rf debug/

deps:
	$(CXX) -MM src/*.cpp > Makefile.d

-include Makefile.d



