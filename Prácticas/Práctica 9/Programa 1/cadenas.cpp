#include <bits/stdc++.h>

using namespace std;

string nueva_palabra(){
    string str = "";
    for( int i = 0; i < 3; i++ )
        str += ( ( rand() % 26 ) + ( 'A' ) );
    str += " ";
    return str;
}

int main(){
    srand( time( NULL ) );
    int n;
    string cadenota = "";
    cin >> n;
    for( int i = 0; i < n; i++ )
        cadenota.append( nueva_palabra() );
    
    int ans = 0;
    int index = 0;
    for( int i = 0; i < cadenota.size(); i++ ){
        index = cadenota.find( "IPN", i );
        if( index != -1 )
            ans++, i = index;
        else 
            break;
    }

    cout << ans << endl;
    return 0;
}