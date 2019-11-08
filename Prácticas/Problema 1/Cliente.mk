Cliente: Cliente.cpp SocketDatagrama.o PaqueteDatagrama.o
	g++ Cliente.cpp SocketDatagrama.o PaqueteDatagrama.o -o Cliente.out
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o PaqueteDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
