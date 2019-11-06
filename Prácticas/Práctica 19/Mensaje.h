#define TAM_MAX_DATA 40000
//Definicion de identificadores para operaciones permitidas
#define DATA 0
#define INFORM 1
// Definicion del formato de mensaje
struct Mensaje
{
    int messageType;        //0= Solicitud, 1 = Respuesta
    unsigned int messageId; //Identificador del mensaje
    char datos[TAM_MAX_DATA];
};