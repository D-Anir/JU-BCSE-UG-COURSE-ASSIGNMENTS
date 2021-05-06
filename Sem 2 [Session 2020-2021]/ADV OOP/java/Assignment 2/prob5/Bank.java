import java.util.ArrayList;
import java.util.Scanner;

public class Bank {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        ArrayList<Customer> cus_list = new ArrayList<>();
        Customer cu;
        int ch = 0, flag = 0, index = 0, priv = 0;
        String id, name, phn;
        double creditP = 0, creditNP = 0, loan = 0, temp = 0;
        while(ch != 10){
            ch = menu();
            switch(ch){
                case 1:
                    if(creditP == 0 && creditNP == 0){
                        System.out.println("No Credit issued by bank! Please Contact the Manager.");
                        break;
                    }
                    cu = new Customer();
                    cu.acceptData(cus_list.size() + 1);
                    index = isAvailable(cu.returnPhone(), cus_list);
                    if(index != -1){
                        System.out.println("Customer Phone Number Already Present! Want to update? (Y/N)");
                        String yes = sc.nextLine();
                        if(yes.toUpperCase().equals("Y")){
                            cus_list.set(index, cu);
                            System.out.println("Customer Updated!");
                            break;
                        }
                        else{
                            System.out.println("No Changes Made!");
                            break;
                        }
                    }
                    if(cu.isPriv())
                        cu.updateCredit(creditP);
                    else
                        cu.updateCredit(creditNP);
                    cus_list.add(cu);
                    System.out.println("Account Added!");
                    break;
                
                case 2:
                    if(cus_list.size() == 0){
                        System.out.println("No Customers to Display!");
                        break;
                    }
                    System.out.println("Enter Customer Id:");
                    id = sc.nextLine();
                    index = isIDAvailable(id, cus_list);
                    if(index == -1){
                        System.out.println("Customer does not exist!");
                        break;
                    }
                    cus_list.get(index).displayCustomer();
                    break;
                
                case 3:
                    System.out.println("1. Change Credit of Privileged.");
                    System.out.println("2. Change Credit of Non-Privileged.");
                    System.out.println("Enter Your Choice:");
                    priv = sc.nextInt();
                    sc.nextLine();
                    switch(priv){
                        case 1:
                            System.out.println("Current Credit Limit of Privileged: Rs. " + creditP);
                            System.out.println("Enter New Credit:");
                            temp = creditP;
                            creditP = sc.nextDouble();
                            sc.nextLine();
                            if(creditP < creditNP){
                                System.out.println("Please enter a value higher than Rs. " + creditNP);
                                creditP = temp;
                                break;
                            }
                            updateAllPCredits(cus_list, creditP);
                            System.out.println("Credit Updated!");
                            break;
                        case 2:
                            System.out.println("Current Credit Limit of Non-Privileged: Rs. " + creditNP);
                            System.out.println("Enter New Credit:");
                            temp = creditP;
                            creditNP = sc.nextDouble();
                            sc.nextLine();
                            if(creditNP > creditP && creditP != 0){
                                System.out.println("Please enter a value less than Rs. " + creditP);
                                break;
                            }
                            updateAllNPCredits(cus_list, creditNP);
                            System.out.println("Credit Updated!");
                            break;
                    }
                    break;
                
                case 4:
                    if(cus_list.size() == 0){
                        System.out.println("No Customers Available!");
                        break;
                    }
                    System.out.println("Enter Customer Id:");
                    id = sc.nextLine();
                    index = isIDAvailable(id, cus_list);
                    if(index == -1){
                        System.out.println("Customer does not exist!");
                        break;
                    }
                    String prevName = cus_list.get(index).returnName();
                    System.out.println("Enter New Name:");
                    name = sc.nextLine();
                    updateName(cus_list, name, prevName);
                    System.out.println("Name Updated!");
                    break;
                
                case 5:
                    if(cus_list.size() == 0){
                        System.out.println("No Customers Available!");
                        break;
                    }
                    System.out.println("Enter Customer Id:");
                    id = sc.nextLine();
                    index = isIDAvailable(id, cus_list);
                    if(index == -1){
                        System.out.println("Customer does not exist!");
                        break;
                    }
                    String prevPhone = cus_list.get(index).returnPhone();
                    System.out.println("Enter New Phone Number:");
                    phn = sc.nextLine();
                    updatePhone(cus_list, phn, prevPhone);
                    System.out.println("Phone Updated!");
                    break;
                
                case 6:
                    if(cus_list.size() == 0){
                        System.out.println("No Customers Available!");
                        break;
                    }
                    if(creditP == 0.0){
                        System.out.println("No Privileged Credit issued by bank! Please Contact the Manager.");
                        break;
                    }
                    System.out.println("Enter Customer Id:");
                    id = sc.nextLine();
                    index = isIDAvailable(id, cus_list);
                    if(index == -1){
                        System.out.println("Customer does not exist!");
                        break;
                    }
                    if(cus_list.get(index).isPriv()){
                        System.out.println("Customer Aready Privileged!");
                        break;
                    }
                    cus_list.get(index).makePriviliged(creditP);
                    System.out.println("Credit Limit changed!");
                    break;
                
                case 7:
                    if(cus_list.size() == 0){
                        System.out.println("No Customers Available!");
                        break;
                    }
                    System.out.println("Enter Customer Id:");
                    id = sc.nextLine();
                    index = isIDAvailable(id, cus_list);
                    if(index == -1){
                        System.out.println("Customer does not exist!");
                        break;
                    }
                    System.out.println("Enter Loan Amount");
                    loan = sc.nextDouble();
                    sc.nextLine();
                    boolean done = cus_list.get(index).isLoanAvailable(loan);
                    if(done){
                        System.out.println("Loan Sanctioned!");
                    }
                    else{
                        System.out.println("Credit Limit Reached!");
                    }
                    break;
                case 8:
                    if(cus_list.size() == 0){
                        System.out.println("No Customers Available!");
                        break;
                    }
                    System.out.println("Enter Customer Id:");
                    id = sc.nextLine();
                    index = isIDAvailable(id, cus_list);
                    if(index == -1){
                        System.out.println("Customer does not exist!");
                        break;
                    }
                    cus_list.get(index).displayCustomer();
                    System.out.println("Can seek a loan of less than or equal to Rs. " + cus_list.get(index).canSeek());
                    break;

                case 9:
                    if(cus_list.size() == 0){
                        System.out.println("No Customers Available!");
                        break;
                    }
                    displayAllAccounts(cus_list);
                    break;

                case 10:
                    System.exit(0);
                
                default:
                    System.out.println("Wrong Choice!");
            }
        }
    }

    static int menu(){
        Scanner sc = new Scanner(System.in);
        System.out.println("\n***BANK MNAGEMENT SYSTEM***");
        System.out.println("1. Add Customer.");
        System.out.println("2. Display Customer Details.");
        System.out.println("3. Enter/Change Credit Limit(same for all customers): ");
        System.out.println("4. Update Name.");
        System.out.println("5. Update Phone Number.");
        System.out.println("6. Make Customer Privileged.");
        System.out.println("7. Request for Loan.");
        System.out.println("8. Show Credit and Loan Details.");
        System.out.println("9. Display All Accounts.");
        System.out.println("10. Exit.");
        int choice;
        System.out.println("Enter Your Choice:");
        choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }

    static int isAvailable(String phone, ArrayList<Customer> cu_list){
        int index = 0;
        for(Customer a: cu_list){
            if(a.returnPhone().equals(phone)){
                return index;
            }
            index++;
        }
        return -1;
    }

    static int isIDAvailable(String id, ArrayList<Customer> cu_list){
        int index = 0;
        for(Customer a: cu_list){
            if(a.returnID().equals(id)){
                return index;
            }
            index++;
        }
        return -1;
    }

    static void updateAllNPCredits(ArrayList<Customer> list, double credit){
        for(Customer a : list){
            if(!a.isPriv())
                a.updateCredit(credit);
        }
    }

    static void updateAllPCredits(ArrayList<Customer> list, double credit){
        for(Customer a : list){
            if(a.isPriv())
                a.updateCredit(credit);
        }
    }

    static void updateName(ArrayList<Customer> list, String name, String prevName){
        for(Customer a : list){
            if(a.returnName().equals(prevName)){
                a.updateName(name);
            }
        }
    }

    static void updatePhone(ArrayList<Customer> list, String phone, String prevPhone){
        for(Customer a : list){
            if(a.returnName().equals(prevPhone)){
                a.updateName(phone);
            }
        }
    }

    static void displayAllAccounts(ArrayList<Customer> list){
        for(Customer a : list){
            a.displayCustomer();
        }
    }
}
