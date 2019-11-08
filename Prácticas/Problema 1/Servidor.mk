Servidor: Servidor.cpp SocketDatagrama.o PaqueteDatagrama.o
	g++ Servidor.cpp SocketDatagrama.o PaqueteDatagrama.o -o Servidor.out
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o PaqueteDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
