Cliente: Cliente.cpp SocketMuilticast.o
	g++ Cliente.cpp SocketMuilticast.o PaqueteDatagrama.o -o Cliente
SocketMuilticast.o: SocketMuilticast.cpp PaqueteDatagrama.o SocketMuilticast.h
	g++ SocketMuilticast.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
