import java.util.Scanner;

class BankAcct{
        private String acc_number;
        private double balance;
        private double int_rate;

    public BankAcct(){
        acc_number = "NA";
        balance = 0.0;
        int_rate = 0.0;
    }

    public void acceptAccount(double r){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Account Number:");
        acc_number = sc.nextLine();
        System.out.println("Enter Deposit Balance:");
        balance  = sc.nextDouble();
        sc.nextLine();
        int_rate = r;
    }

    public void displayAccount(){
        System.out.println("Account Number: " + acc_number);
        System.out.println("Current Balance: Rs. " + balance);
        System.out.println("Current Rate of Interest: " + int_rate + "%");
    }

    public double returnInterest(){
        return (balance * int_rate)/100 ;
    }

    public void updateRate(double r){
        int_rate = r;
    }

    public double returnBalance(){
        return balance;
    }

    public String returnAccNumber(){
        return acc_number;
    }
}