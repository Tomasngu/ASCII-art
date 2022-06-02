CXX=g++
CXXFLAGS = -Wall -pedantic -std=c++17 -g 

all: app

run: app
	-rm -f src/*.o
	./app

app: src/main.o src/CFormatTGA.o src/CImage.o src/CFormat.o src/CFormatBMP.o src/CApplication.o src/CImageCheck.o src/CFilterRotate.o src/CFilterRotateL.o  src/CFilterRotateR.o src/CFilterMirror.o src/CFilterFlip.o src/CFilterDark.o src/CFilterBright.o src/CFilterInverse.o src/CFilterResize.o src/CImageHandler.o src/CVideo.o src/CVideoHandler.o src/ArgLoader.o
	$(CXX) $(CXXFLAGS) -o $@ $^ 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	-rm -f src/*.o
	-rm app
	
deps:
	$(CXX) -MM src/*.cpp > Makefile.d
-include Makefile.d



