import java.util.Scanner;

public class one {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        short a=0,b=0;
        System.out.println("Enter a short integer: ");
        a = sc.nextShort();
        b = sc.nextShort();
        int c = a+b;
        System.out.println("Sum = " + c);
        sc.close();
        System.out.println(6+7+"abc");
    }
}
