#include <bits/stdc++.h>

using namespace std;

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
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cadenita = nueva_palabra();
        memcpy(cadenota + strlen( cadenota ), cadenita, sizeof(cadenita));
    }
    int ans = 0;
    char ipn [ 3 ] = {'I', 'P', 'N'};
    for( int i = 0; i < strlen( cadenota ); i++){
        for( int j = i, k = 0, c = 0; j < i + 3; j++, k++ ){
            if( ipn[ k ] != cadenota[ j ] )
                break;
            else
                c++;
            if( c == 3 )
                ans++;
        }
    }
    cout << cadenota << endl;
    cout << ans << endl;
    
    
    return 0;
}