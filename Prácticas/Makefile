all: main

main: Coordenada.o Gusano.o gfx.o
	g++ gfx.o main.o Coordenada.o Gusano.o -lX11 -o main
main.o: main.cpp
	g++ main.cpp -c
Gusano.o: Gusano.cpp
	g++ Gusano.cpp -c
Coordenada.o: Coordenada.cpp
	g++ Coordenada.cpp -c
