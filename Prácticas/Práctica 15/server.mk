Server: Server.cpp SocketDatagrama.o
	g++ Server.cpp SocketDatagrama.o PaqueteDatagrama.o -o Server
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
