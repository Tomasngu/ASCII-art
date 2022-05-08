CXX=g++
CXXFLAGS = -g -std=c++17 -Wall -pedantic -fsanitize=address

all: app
	-rm -f src/*.o
run: app
	-rm -f src/*.o
	./app

app: src/main.o src/CFormatTGA.o src/CImage.o src/CFormat.o src/CFormatBMP.o src/CApplication.o src/CImageCheck.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	-rm -f src/*.o
	-rm app
	
deps:
	$(CXX) -MM src/*.cpp > Makefile.d
-include Makefile.d



