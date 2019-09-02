class Calculos_numericos{
    public static void main(String args[]){
        double i = 0, MAX = 10000000;
        System.out.println( MAX );
        double seno = 0, coseno = 0, tangente = 0, logaritmo = 0, raizCuadrada = 0;
        while( i < MAX ){
            seno += Math.sin( i );
            coseno += Math.cos( i );
            tangente += Math.tan( i );
            logaritmo += Math.log( i );
            raizCuadrada += Math.sqrt( i );
            i++;
        }
    }
}