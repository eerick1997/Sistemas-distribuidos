Server: Server.cpp SocketMulticast.o SocketDatagrama.o PaqueteDatagrama.o
	g++ Server.cpp SocketMulticast.o SocketDatagrama.o PaqueteDatagrama.o -o Server -pthread
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o PaqueteDatagrama.h
	g++ SocketDatagrama.cpp -c
SocketMulticast.o: SocketMulticast.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketMulticast.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
