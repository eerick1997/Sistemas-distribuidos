#include <stdio.h>

int main(){
    int i = 0;

    char caracter = 0;
    int entero = 0;
    float flotante = 0;
    long largo = 0;
    double doble = 0;
    long long int direccion = 0;

    char *pcaracter;
    int *pentero;
    float *pflotante;
    long *plargo;
    double *pdoble;
    long long int *pdireccion;

    char cadena[] = "ESCOM - IPN";

    printf("\n%p, %d", (&caracter), sizeof(caracter));
    printf("\n%p, %d", (&entero), sizeof(entero));
    printf("\n%p, %d", (&flotante), sizeof(flotante));
    printf("\n%p, %d", (&largo), sizeof(largo));
    printf("\n%p, %d", (&doble), sizeof(doble));

    printf("\n%p, %d", ( (&caracter) ), sizeof(caracter));
    printf("\n%p, %d", ( (&entero) ), sizeof(entero));
    printf("\n%p, %d", ( (&flotante) ), sizeof(flotante));
    printf("\n%p, %d", ( (&largo) ), sizeof(largo));
    printf("\n%p, %d", ( (&doble) ), sizeof(doble));

    printf("\nApuntador -> %p, \t Tamaño: %d", (&doble), sizeof(&doble));
    
    direccion = (&doble);
    printf("\n %p ", (direccion));

    printf("\n%p, %d", (&pcaracter), sizeof(pcaracter));
    printf("\n%p, %d", (&pentero), sizeof(pentero));
    printf("\n%p, %d", (&pflotante), sizeof(pflotante));
    printf("\n%p, %d", (&plargo), sizeof(plargo));
    printf("\n%p, %d", (&pdoble), sizeof(pdoble));

    for( i = 0; i < 12; i++ )
        printf( "\ncaracter: %c, \t direccion: %p ", cadena[ i ], (&cadena[ i ]) );

    printf( "\ncadena + 4: %c, \t direccion: %p ", ((&cadena) + 4), ((&cadena + 4)));
    return 0;
}   