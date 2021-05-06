import java.util.Scanner;

class Customer{
        private String cusId;
        private String phnNumber;
        private String name;
        private double currLoan;
        private double credit;
        private boolean isPrivileged;
        
    public Customer(){
        cusId = "";
        name = "";
        currLoan = 0.0;
        phnNumber = "";
        credit = 0.0;
        isPrivileged = false;
    }

    public void acceptData(int id){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name:");
        name = sc.nextLine();
        System.out.println("Enter Phone Number:");
        phnNumber = sc.nextLine();
        cusId = this.generateId(id);
        System.out.println("Auto-Generated ID: " + cusId);
    }

    public void displayCustomer(){
        System.out.println("\nCustomer ID: " + cusId);
        System.out.println("Customer Name: " + name);
        System.out.println("Customer Phone Number: " + phnNumber);
        System.out.println("Current Credit Limit: Rs. " + credit);
        System.out.println("Current Loan: Rs. " + currLoan);
    }

    public String generateId(int i){
        return "100" + String.valueOf(i);
    }

    public void updateCredit(double c){
        credit = c;
    }

    public void updateName(String n){
        name = n;
    }

    public void updatePhone(String p){
        phnNumber = p;
    }

    public boolean isLoanAvailable(double amt){
        if((amt + currLoan) <= credit){
            currLoan += amt; 
            return true;
        }
        return false;
    }

    public void makePriviliged(double amt){
        isPrivileged = true;
        credit = amt;
    }

    public String returnName(){
        return name;
    }

    public double returnCurrentLoan(){
        return currLoan;
    }

    public double returnCredit(){
        return credit;
    }

    public String returnPhone(){
        return phnNumber;
    }

    public boolean isPriv(){
        return isPrivileged;
    }

    public double canSeek(){
        return credit - currLoan;
    }

    public String returnID(){
        return cusId;
    }
}