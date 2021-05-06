import java.util.Scanner;

public class operations {
    // menu 1
    static int SeoMenu() {
        System.out.println("\n**STOCK ENTRY OPERATOR MENU**");
        System.out.println("1. Add Item.");
        System.out.println("2. Change Rate.");
        System.out.println("3. Check Item Details.");
        System.out.println("4. Issue Item.");
        System.out.println("5. Receive Item.");
        System.out.println("6. Check Items with Minimum Price.");
        System.out.println("7. Exit.");
        System.out.println("Enter Your choice: ");
        int choice;
        Scanner sc = new Scanner(System.in);
        choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }

    // menu 2
    static int SkMenu() {
        System.out.println("\n**SHOPKEPER MENU**");
        System.out.println("1. Issue Item.");
        System.out.println("2. Receive Item.");
        System.out.println("3. Check Item Details.");
        System.out.println("4. Check Items with Minimum Price.");
        System.out.println("5. Exit.");
        System.out.println("Enter Your choice: ");
        int choice;
        Scanner sc = new Scanner(System.in);
        choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }

    public static void main(String args[]){
        ItemList IL = new ItemList();       //instance of ItemList class
        int choice = 0;
        int tempInt = 0;
        String tempString = "";
        Scanner sc = new Scanner(System.in);
        while(!tempString.equals("STOP")){
            System.out.println("\nStock Entry Operator(SEO) OR Shopkeeper(SK) OR STOP ? ");
            tempString = sc.nextLine();
            if(tempString.equals("SEO")){
                while (choice != 7) {
                    choice = SeoMenu();
                    switch (choice) {
                        case 1:
                            IL.addItem();
                            break;
                        case 2:
                            System.out.println("Enter Item Code:");
                            tempString = sc.nextLine();

                            // check if code is already present
                            if(IL.isCodePresent(tempString)){
                                System.out.println("Enter New Rate: ");
                                tempInt = sc.nextInt();
                                sc.nextLine();
                                IL.changeRate(tempString, tempInt);
                            }
                            else{
                                System.out.println("Invalid Item Code!");
                            }
                            break;
                        case 3:
                            System.out.println("Enter Item Code:");
                            tempString = sc.nextLine();

                            // check if code is already present
                            if(IL.isCodePresent(tempString)){
                                IL.showDetails(tempString);
                            }
                            else{
                                System.out.println("Invalid Item Code!");
                            }
                            break;
                        case 4:
                            System.out.println("Enter Item Code:");
                            tempString = sc.nextLine();
                            if(IL.isCodePresent(tempString)){
                                System.out.println("Enter quantity to be Issued:");
                                tempInt = sc.nextInt();
                                sc.nextLine();
                                IL.issue(tempInt, tempString);
                            }
                            else{
                                System.out.println("Invalid Item Code!");
                            }
                            break;
                        case 5:
                            System.out.println("Enter Item Code:");
                            tempString = sc.nextLine();
                            if(IL.isCodePresent(tempString)){
                                System.out.println("Enter quantity to be Received:");
                                tempInt = sc.nextInt();
                                sc.nextLine();
                                IL.receive(tempInt, tempString);
                            }
                            else{
                                System.out.println("Invalid Item Code!");
                            }
                            break;
                        case 6:
                            System.out.println("Enter Minimum Price:");
                            tempInt = sc.nextInt();
                            sc.nextLine();
                            IL.displayElementsWithMinimumPrice(tempInt);
                            break;
                        case 7:
                            break;
                        default:
                            System.out.println("Invalid Choice!");
                    }
                }
            }
            else if(tempString.equals("SK")){
                while (choice != 5) {
                    choice = SkMenu();
                    switch (choice) {
                        case 1:
                            System.out.println("Enter Item Code:");
                            tempString = sc.nextLine();
                            if(IL.isCodePresent(tempString)){
                                System.out.println("Enter Number to be Issued:");
                                tempInt = sc.nextInt();
                                sc.nextLine();
                                IL.issue(tempInt, tempString);
                            }
                            else{
                                System.out.println("Invalid Item Code!");
                            }
                            break;
                        case 2:
                            System.out.println("Enter Item Code:");
                            tempString = sc.nextLine();
                            if(IL.isCodePresent(tempString)){
                                System.out.println("Enter Number to be Received:");
                                tempInt = sc.nextInt();
                                sc.nextLine();
                                IL.receive(tempInt, tempString);
                            }
                            else{
                                System.out.println("Invalid Item Code!");
                            }
                            break;
                        case 3:
                            System.out.println("Enter Item Code:");
                            tempString = sc.nextLine();
                            if(IL.isCodePresent(tempString)){
                                IL.showDetails(tempString);
                            }
                            else{
                                System.out.println("Invalid Item Code!");
                            }
                            break;
                        case 4:
                            System.out.println("Enter Minimum Price:");
                            tempInt = sc.nextInt();
                            sc.nextLine();
                            IL.displayElementsWithMinimumPrice(tempInt);
                            break;
                        case 5:
                            break;
                        default:
                            System.out.println("Invalid Choice!");
                    }
                }
            }
            else if(!tempString.equals("STOP") && !tempString.equals("SK") && !tempString.equals("SEO")){
                System.out.println("No Such Users Available! Kindly contact the Shop Owner");
            }
        }
    }
}
