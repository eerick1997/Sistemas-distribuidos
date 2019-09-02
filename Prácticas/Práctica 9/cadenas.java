import java.util.Random;
import java.util.Scanner;


class cadenas{

    public static String nueva_palabra(){
        String cadenita = "";
        Random random = new Random();
        for( int i = 0; i < 3; i++ )
            cadenita += (char)(( random.nextInt(26) ) + 'A');
        cadenita += " ";
        return cadenita;
    }

    public static void main(String args[]){
        Scanner scan = new Scanner( System.in );
        int ans = 0;
        String cadenota = "";
        String token = "IPN";
        int n = scan.nextInt();
        
        for( int i = 0; i < n; i++ )
            cadenota += nueva_palabra();
        
        for( int i = 0; i < cadenota.length(); i++ ){
            for( int j = i, k = 0, c = 0; k < 3; j++, k++ ){
                if( token.charAt( k ) !=  cadenota.charAt( j ))
                    break;
                else 
                    c++;
                if( c == 3 )
                    ans++;
            }
        }

        System.out.println( cadenota );
        System.out.println( ans );
    }
}