all: project

project: Gusano.o Coordenada.o gfx.o main.o
	g++ gfx.o Gusano.o Coordenada.o main.o -lX11 -o main 
gfx.o: gfx.c
	gcc gfx.c -c
Gusano.o: Gusano.cpp
	g++ Gusano.cpp -c
Coordenada.o: Coordenada.cpp
	g++ Coordenada.cpp -c
main.o: main.cpp
	g++ main.cpp -c
