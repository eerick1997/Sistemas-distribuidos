#include <bits/stdc++.h>
#include "Numero.h"

using namespace std;
typedef long long int lli;

int main(){
    lli n, raiz;
    vector< Numero > criba;
    cin >> n;
    criba.assign( n + 1, Numero() );
    criba[ 0 ].ponEsPrimo( false ); 
    criba[ 0 ].ponNumero( 0 );
    criba[ 1 ].ponEsPrimo( false );
    criba[ 1 ].ponNumero( 1 );

    for( int i = 4; i <= n; i += 2){
        criba[ i ].ponNumero( i );
        criba[ i ].ponEsPrimo( false );
    }
    raiz = sqrt( n );
    for( int i = 3; i <= n; i += 2 ){
        criba[ i ].ponNumero( i );
        if( criba[ i ].obtenEsPrimo() ){
            if( i <= raiz ){
                for( int j = i * i; j <= n; j += 2 * i ){
                    criba[ j ].ponEsPrimo( false );
                    if( criba[ j ].obtenNumero() != 0 )
                        criba[ j ].ponNumero( j );
                }
            }
        }
    }

    for( auto nn : criba )
        if( nn.obtenEsPrimo() )
            cout << nn.obtenNumero() << " ";
    cout << endl;
    return 0;
}