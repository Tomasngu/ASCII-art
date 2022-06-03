CXX=g++
CXXFLAGS = -Wall -pedantic -std=c++17 -g
LIBRARIES = -lstdc++fs

HEADERS = $(wildcard src/*.h)
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)

all: app

run: app
	-rm -f src/*.o
	./app

app: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^  $(LIBRARIES)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

clean:
	-rm -f src/*.o
	-rm app
	
deps:
	$(CXX) -MM src/*.cpp > Makefile.d
-include Makefile.d



