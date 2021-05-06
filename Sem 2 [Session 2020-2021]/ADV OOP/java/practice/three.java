import java.util.Scanner;

public class three {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int h_in_cm;
        System.out.println("Enter height: ");
        h_in_cm = sc.nextInt();

        double h_in_ft, h_in_inch;
        
        h_in_ft = h_in_cm / 30.5 ; 
        h_in_inch = h_in_cm / 2.54;
        System.out.println("Height in Foot: " + h_in_ft +"\n" + "Height in Inch: " + h_in_inch );
        sc.close();
    }
}
