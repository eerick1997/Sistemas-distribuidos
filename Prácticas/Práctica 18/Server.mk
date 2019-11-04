Server: Server.cpp SocketMuilticast.o SocketDatagrama.o PaqueteDatagrama.o
	g++ Server.cpp SocketMuilticast.o SocketDatagrama.o PaqueteDatagrama.o -o Server
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o PaqueteDatagrama.h
	g++ SocketDatagrama.cpp -c
SocketMuilticast.o: SocketMuilticast.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketMuilticast.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
