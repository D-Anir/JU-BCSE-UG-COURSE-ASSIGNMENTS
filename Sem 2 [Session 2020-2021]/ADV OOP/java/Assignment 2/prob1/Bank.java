import java.util.ArrayList;
import java.util.Scanner;

public class Bank {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        ArrayList<BankAcct> acc_list = new ArrayList<>();
        BankAcct ac;
        int ch = 0, flag = 0, index = 0;
        String name;
        double rate = 0, interest = 0, balance = 0;
        while(ch!=6){
            ch = menu();
            switch(ch){
                case 1:
                    if(rate == 0){
                        System.out.println("No Rate issued by bank! Please Contact the Manager.");
                        break;
                    }
                    ac = new BankAcct();
                    ac.acceptAccount(rate);
                    index = isAvailable(ac.returnAccNumber(), acc_list);
                    if(index != -1){
                        System.out.println("Account already present! Want to update? (Y/N)");
                        String yes = sc.nextLine();
                        if(yes.toUpperCase().equals("Y")){
                            acc_list.set(index, ac);
                            System.out.println("Account Updated!");
                            break;
                        }
                        else{
                            System.out.println("No Changes Made!");
                            break;
                        }
                    }
                    acc_list.add(ac);
                    System.out.println("Account Added!");
                    break;
                
                case 2:
                    if(acc_list.size() == 0){
                        System.out.println("No Accounts to Display!");
                        break;
                    }
                    System.out.println("Enter Account Number:");
                    name = sc.nextLine();
                    index = isAvailable(name, acc_list);
                    if(index == -1){
                        System.out.println("Account does not exist!");
                        break;
                    }
                    acc_list.get(index).displayAccount();
                    break;
                
                case 3:
                    System.out.println("Current Rate of Interest(per annum): " + rate + "%");
                    System.out.println("Enter New Rate:");
                    rate = sc.nextDouble();
                    sc.nextLine();
                    updateAllRates(acc_list, rate);
                    System.out.println("Rate Updated!");
                    break;
                
                case 4:
                    if(acc_list.size() == 0){
                        System.out.println("No Accounts Available!");
                        break;
                    }
                    System.out.println("Enter Account Number:");
                    name = sc.nextLine();
                    index = isAvailable(name, acc_list);
                    if(index == -1){
                        System.out.println("Account does not exist!");
                        break;
                    }
                    balance = acc_list.get(index).returnBalance();
                    interest = acc_list.get(index).returnInterest();
                    System.out.println("Current Interest on balance Rs. " + balance + ": Rs. " + interest);
                    break;
                
                case 5:
                    if(acc_list.size() == 0){
                        System.out.println("No Accounts Available!");
                        break;
                    }
                    displayAllAccounts(acc_list);
                    break;
                
                case 6:
                    System.exit(0);
                
                default:
                    System.out.println("Wrong Choice!");
            }
        }
    }
    static int menu(){
        Scanner sc = new Scanner(System.in);
        System.out.println("\n***BANK MNAGEMENT SYSTEM***");
        System.out.println("1. Add Account.");
        System.out.println("2. Display Account.");
        System.out.println("3. Enter/Change Rate of Interest(same for all accounts): ");
        System.out.println("4. Calculate and Return Interest(per annum).");
        System.out.println("5. Display All Accounts.");
        System.out.println("6. Exit.");
        int choice;
        System.out.println("Enter Your Choice:");
        choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }

    static int isAvailable(String name, ArrayList<BankAcct> acc_list){
        int index = 0;
        for(BankAcct a: acc_list){
            if(a.returnAccNumber().equals(name)){
                return index;
            }
            index++;
        }
        return -1;
    }

    static void updateAllRates(ArrayList<BankAcct> list, double rate){
        for(BankAcct a : list){
            a.updateRate(rate);
        }
    }

    static void displayAllAccounts(ArrayList<BankAcct> list){
        for(BankAcct a : list){
            a.displayAccount();
        }
    }
}
