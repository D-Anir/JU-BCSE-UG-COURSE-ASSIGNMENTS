import java.util.Scanner;

public class nine {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Data to be converted:");
        double data = 0.0;
        data = sc.nextInt();
        System.out.println("Convert into Kilometers(K) or Miles(M)?");
        char choice;
        sc.nextLine();
        choice = sc.next().charAt(0);
        System.out.println("Converted Data = " + convert(data, choice));
        sc.close();
    }
    public static double convert(double data, char KiloMile){
        if(KiloMile == 'M')
            return data/1.5;
        else
            return data*1.5;
    }
}
