import java.util.Scanner;


// store item information
public class Item {
        private String item_code;
        private String name;
        private int rate;
        private int quantity;
    
    // constructor
    public Item(){
        item_code = "";
        name = "";
        rate = -1;
        quantity = 0;
    }

    // accept data from user
    public void getData(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name: ");
        name = sc.nextLine();
        System.out.println("Enter Rate: ");
        rate = sc.nextInt();
        sc.nextLine();
        quantity++;
    }

    // display
    public void showData(){
        System.out.println("\nItem Code: " + item_code);
        System.out.println("Item Name: " + name);
        System.out.println("Item Price: " + rate);
        System.out.println("Quantity Available: " + quantity);
    }

    // modifier function to change rate
    public void changeRate(int r){
        rate = r;
    }

    // generate item_code automatically in the format ITEMNAME + 00 + SEREALNUMBER
    public void generateItemCode(int n){
        String temp;
        if(n<10){
            temp = "00";
        }
        else{
            temp = "0";
        }
        temp = temp + String.valueOf(n);
        item_code = name.substring(0,3).toUpperCase() + temp;
    }

    // modify quantity for issue and receive
    public void changeQuantity(int isIssue, int items){
        if(isIssue == 1){
            quantity = quantity - items; 
        }
        else{
            quantity = quantity + items;
        }
    }

    // check if item is available
    public boolean isAvailable(int items){
        return ((quantity-items) >= 0);
    }

    // accessor function to return name
    public String returnName(){
        return name;
    }

    // accessor function to return code
    public String returnCode(){
        return item_code;
    }

    // accessor function to return rate
    public int returnRate(){
        return rate;
    }

}
