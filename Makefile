CXX=g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic

all: psfit

run: psfit
	-rm -f src/*.o
	-rm psfit
	./psfit

psfit: src/main.o src/CFormatTGA.o 
	$(CXX) $(CXXFLAGS) -o $@ $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	-rm -f src/*.o
	-rm psfit
	
deps:
	$(CXX) -MM src/*.cpp > Makefile.d
-include Makefile.d



