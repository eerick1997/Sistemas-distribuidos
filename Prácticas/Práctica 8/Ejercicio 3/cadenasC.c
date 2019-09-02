#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

char* nueva_palabra(){
    char *cadenita = (char *)malloc( 4 * sizeof( char ) );
    for( int i = 0; i < 3; i++)
        cadenita[ i ] = (rand() % 26) + 'A';
    cadenita[ 3 ] = ' ';
    return cadenita;
}

int main(){
    int n;
    srand( time(NULL) );
    char *cadenota = (char *)calloc( 0, sizeof(cadenota + 1) );
    char *cadenita = NULL;
    int posicion;
    scanf("%d", &n);
    for( int i = 0; i < n; i++ ){
        cadenita = nueva_palabra();
        memcpy(cadenota + i * 4, cadenita, sizeof(cadenita));
    }
    int ans = 0;
    char ipn [ 3 ] = {'I', 'P', 'N'};
    for( int i = 0; i < 4 * n; i++){
        for( int j = i, k = 0, c = 0; j < i + 3; j++, k++ ){
            if( ipn[ k ] != cadenota[ j ] )
                break;
            else
                c++;
            if( c == 3 )
                ans++;
        }
    }
    printf("%d", ans);
    return 0;
}