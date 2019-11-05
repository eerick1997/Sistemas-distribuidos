function get_directories(){
    file_name = findFirstFile("*.*");
    while( fileName.length ){
        write( file_name );
        file_name = findNextFile();
    }
}