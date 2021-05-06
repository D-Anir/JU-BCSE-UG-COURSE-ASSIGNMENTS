import java.util.Scanner;

class Metric{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        double argument;
        int choice = 0;
        while(choice != 3){
            choice = menu();
            switch(choice){
                case 1:
                    System.out.println("Enter Kilometer value:");
                    argument = sc.nextDouble();
                    sc.nextLine();
                    System.out.println(argument + " kms = " + kiloToMile(argument) + " miles.");
                    break;
                case 2:
                    System.out.println("Enter Miles value:");
                    argument = sc.nextDouble();
                    sc.nextLine();
                    System.out.println(argument + " miles = " + mileToKilo(argument) + " kms.");
                    break;
                case 3:
                    System.exit(0);
                default:
                    System.out.println("Wrong Choice!");
            }
        }
    }

    static int menu(){
        Scanner sc = new Scanner(System.in);
        System.out.println("\n**UNIT CONVERSION MENU**");
        System.out.println("1. Kilometers to Miles.");
        System.out.println("2. Miles to Kilometers.");
        System.out.println("3. Exit.");
        System.out.println("Enter Your Choice:");
        int choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }

    static double kiloToMile(double kilometers){
        return kilometers/1.5 ;
    }

    static double mileToKilo(double miles){
        return miles*1.5;
    }
}