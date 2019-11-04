Cliente: Cliente.cpp SocketMuilticast.o SocketDatagrama.o PaqueteDatagrama.o
	g++ Cliente.cpp SocketMuilticast.o SocketDatagrama.o PaqueteDatagrama.o -o Cliente
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o PaqueteDatagrama.h
	g++ SocketDatagrama.cpp -c
SocketMuilticast.o: SocketMuilticast.cpp PaqueteDatagrama.o SocketMuilticast.h
	g++ SocketMuilticast.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
