all: hello

hello: main.o Login.o Display.o
	g++ main.o Login.o Display.o -o hello

main.o:main.cpp 
	g++ -c main.cpp

Login.o:./SourceFiles/Login.cpp
	g++ -c ./SourceFiles/Login.cpp

Display.o:./SourceFiles/Display.cpp
	g++ -c ./SourceFiles/Display.cpp