#define TAM_MAX_DATA 4000

#define suma 1

struct mensaje{
    //0 = SOLICITUD
    //1 = RESPUESTA
    int messageType;
    //Identificador del mensaje
    unsigned int requestID;
    //Identificador de la operación
    int operationID;
    char arguments[TAM_MAX_DATA];
};