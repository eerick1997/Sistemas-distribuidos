Server: Server.cpp Respuesta.o
	g++ Server.cpp Respuesta.o SocketDatagrama.o PaqueteDatagrama.o -o Server
Respuesta.o: Respuesta.cpp SocketDatagrama.o Respuesta.h
	g++ Respuesta.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o SocketDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c