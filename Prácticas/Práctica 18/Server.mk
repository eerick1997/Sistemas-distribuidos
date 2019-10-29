Server: Server.cpp SocketMuilticast.o
	g++ Server.cpp SocketMuilticast.o PaqueteDatagrama.o -o Server
SocketMuilticast.o: SocketMuilticast.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketMuilticast.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
