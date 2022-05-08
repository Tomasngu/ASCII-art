CXX=g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic -fsanitize=address

all: psfit
	-rm -f src/*.o
run: psfit
	-rm -f src/*.o
	./psfit

psfit: src/main.o src/CFormatTGA.o src/CImage.o src/CFormat.o src/CFormatBMP.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	-rm -f src/*.o
	-rm psfit
	
deps:
	$(CXX) -MM src/*.cpp > Makefile.d
-include Makefile.d



