#include "../Libraries/Solicitud.h"
#include <sys/stat.h>
#include <vector>
#include <string>
#include <thread>

using namespace std;

const uint32_t port = 7200;
vector< string > IPrange; 


void get_ip_range( string IP ) {
    for( int i = 1; i < 2; i++ )
        IPrange.push_back( IP + to_string( i ) );
}

void send_request_ss( int8_t quality ) {
    Solicitud request;
    string Command = "scrot screen_shoot.png -q " + to_string( quality );
    for( auto IP: IPrange ) {
        char *ip = new char[ IP.length() ];
        char *command = new char[ Command.length() ];
        int32_t number_of_packets;
        strcpy( ip, IP.c_str() );
        strcpy( command, Command.c_str() );
        cout << ip << endl;
        cout << command << endl;
        vector< int  > image = request.doOperation( ip, port, 1, command );
        if( image.size() > 0 ){
            ofstream out( "Images/" + IP + ".png", ios::binary );
            for( auto byte : image ){
                if( byte == -1 ){
                    out.close();
                    break;
                }
                out.put( byte );
            } 
        }
    }
}

int main(){
    int16_t quality, time;
    cin >> quality >> time;
    get_ip_range( "127.0.0." );
    mkdir( "Images", 0700 );
    while( true ){
        send_request_ss( quality );
        this_thread::sleep_for( chrono::seconds( time ) );
    }
    return 0;
}