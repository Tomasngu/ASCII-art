CXX=g++
CXXFLAGS = -Wall -pedantic -std=c++17 -g
LIBRARIES = -lstdc++fs

HEADERS = $(wildcard src/*.h)
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:src/%.cpp=obj/%.o)
username = nguyehu7

all: compile doc

compile: $(username)

run: compile
	./$(username)

nguyehu7: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^  $(LIBRARIES)

obj/%.o: src/%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

doc: $(HEADERS) Doxyfile README.md
	doxygen

clean:
	-rm -rf obj/
	-rm $(username)
	-rm -rf doc/

deps:
	$(CXX) -MM src/*.cpp > Makefile.d

-include Makefile.d



