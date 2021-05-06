import java.util.Scanner;

public class four {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        final double pi = 3.14;
        int r;
        System.out.println("Enter radius: ");
        r = sc.nextInt();

        double area;
        
        area = pi*r*r;
        
        System.out.println("Area of Circle: " + area );
        sc.close();
    }
}
