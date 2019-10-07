cliente: Cliente.cpp Solicitud.o
	g++ Cliente.cpp Solicitud.o SocketDatagrama.o PaqueteDatagrama.o -o Cliente
Solicitud.o: Solicitud.cpp SocketDatagrama.o Solicitud.h
	g++ Solicitud.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c