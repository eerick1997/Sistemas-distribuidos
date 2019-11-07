Receiver: Receiver.cpp SocketMulticast.o SocketDatagrama.o PaqueteDatagrama.o
	g++ Receiver.cpp SocketMulticast.o SocketDatagrama.o PaqueteDatagrama.o -o Receiver.out
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o PaqueteDatagrama.h
	g++ SocketDatagrama.cpp -c
SocketMulticast.o: SocketMulticast.cpp PaqueteDatagrama.o SocketMulticast.h
	g++ SocketMulticast.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
