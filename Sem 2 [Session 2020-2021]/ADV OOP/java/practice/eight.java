import java.util.Scanner;

public class eight {
    private String acc_no;
    private double balance;
    private double rate = 10;

    public eight(){

    }

    public eight(String a, double b, double r){
        acc_no = a;
        balance = b;
        rate = r;
    }

    public void changeRate(int r){
        rate = r;
    }

    public void getInfo(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Account No.: ");
        acc_no = sc.nextLine();
        System.out.println("Enter Balance: ");
        balance = sc.nextDouble();
        sc.close();
    }

    public String toString(){
        return ("Account No.: " + acc_no + "\nBalance: " + balance + "\nInterest Rate: " + rate);
    }

    public double returnInterest(){
        return rate*balance;
    }

}
