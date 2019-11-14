Servidor: Servidor.cpp SocketDatagrama.o PaqueteDatagrama.o Solicitud.o Respuesta.o
	g++ Servidor.cpp SocketDatagrama.o PaqueteDatagrama.o Solicitud.o Respuesta.o -o Servidor.out
Respuesta.o: Respuesta.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ Respuesta.cpp -c
Solicitud.o: Solicitud.cpp PaqueteDatagrama.o SocketDatagrama.o
	g++ Solicitud.cpp -c
SocketDatagrama.o: SocketDatagrama.cpp PaqueteDatagrama.o PaqueteDatagrama.h
	g++ SocketDatagrama.cpp -c
PaqueteDatagrama.o: PaqueteDatagrama.cpp PaqueteDatagrama.h
	g++ PaqueteDatagrama.cpp -c
