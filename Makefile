CXX=g++
CXXFLAGS = -Wall -pedantic -std=c++17 -g
LIBRARIES = -lstdc++fs

HEADERS = $(wildcard src/*.h)
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)

all: compile doc

compile: app

run: compile
	./app

app: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^  $(LIBRARIES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

doc: $(HEADERS) Doxyfile README.md
	doxygen

clean:
	-rm -rf $(OBJECTS)
	-rm app
	-rm -rf doc/

deps:
	$(CXX) -MM src/*.cpp > Makefile.d
	
-include Makefile.d



