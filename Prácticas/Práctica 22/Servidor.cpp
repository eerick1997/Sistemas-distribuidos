#include "Respuesta.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <string.h>
#include <algorithm>

using namespace std;


struct Node{
    bool isWord = false;
    map< char, Node* > letters;
};

struct Trie{

    Node *root;

    Trie(){
        root = new Node();
    }

    inline bool exists( Node *actual, const char & c ){
        return actual -> letters.find( c ) != actual -> letters.end();
    }

    void insert_word( const string &word ){
        Node *current = root;
        for( auto & c : word ){
            if( !exists( current, c ) )
                current -> letters[ c ] = new Node();
            current = current -> letters[ c ];
        }
        current -> isWord = true;
    }

    bool find_word( const string &word ){
        Node *current = root;
        for( auto & c: word ){
            if( !exists( current, c ) )
                return false;
            current = current -> letters[ c ];
        }
        return current -> isWord;
    }

};

int main(int32_t argc, char const *argv[]) {

    PaqueteDatagrama paquete_datagrama(34 * sizeof(char));
    struct mensaje *request;
    int32_t file_to_write, a = 0;
    char data[34], timestamp[40];
    timeval tiempo;
    Trie CURP;
    if (argc != 3)
    {
        cout << "Ingresar nombre archivo, archivo a leer, puerto" << endl;
        exit(-1);
    }
    Respuesta respuesta(atoi(argv[2]));

    if ((file_to_write = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0666)) == -1)
        exit(-1);

    while (true)
    {

        request = respuesta.getRequest();
        if (request != NULL)
        {
            memcpy(data, (char *)request->arguments, 31);
            string numero = "";
            for( int i = 0; i < 10; i++ ){
                numero += data[ i ];
                //cout << numero << endl;
            }

            if( !CURP.find_word( numero ) ) {
                CURP.insert_word( numero );
                write(file_to_write, data, 31);
                gettimeofday(&tiempo, NULL);
                int n = sprintf(timestamp, "%ld%ld", tiempo.tv_sec, tiempo.tv_usec);
                write(file_to_write, timestamp, n);
                write(file_to_write, "\n", strlen("\n"));
                fsync(file_to_write);
                //write(1, data, 31);
                //write(1, timestamp, n);
                //write(1, "\n", strlen("\n"));
                respuesta.sendReply((char *)&tiempo, suma);
            } else {
                tiempo.tv_sec = 0; 
                tiempo.tv_usec = 0;
                respuesta.sendReply( (char *)&tiempo, REPETIDO );
            }
            //cout << endl;
        }
        else
        {
            respuesta.sendReply((char *)&a, REPETIDO);
        }
    }

    close(file_to_write);

    return 0;
}