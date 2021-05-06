import java.util.*;


// store list of items (single list of electronics, furniture, etc)
public class ItemList {
        ArrayList<Item> i_list = new ArrayList<Item>();
        static int items_added = 0;

    public ItemList(){

    }

    // add an item to the list
    public void addItem(){
        Scanner sc = new Scanner(System.in);
        Item it = new Item();
        it.getData();
        if(this.isNamePresent(it.returnName())){
            it = this.replaceDuplicate(it.returnName());
            this.changeQuantity(it);
        }
        else{
            items_added++;
            it.generateItemCode(items_added);
            i_list.add(it);
            System.out.println("Auto-generated Item Code: " + it.returnCode());
            System.out.println("Item Added!");
        }
    }

    // change the rate of an item
    public void changeRate(String code, int r){
        for(Item i: i_list){
            if(i.returnCode().equals(code))
                i.changeRate(r);
        }
        System.out.println("Rate Changed!");
    }

    // show data of a particular item
    public void showDetails(String code){
        for(Item i: i_list){
            if(i.returnCode().equals(code))
                i.showData();
        }
    }

    // issue an item
    public void issue(int number, String code){
        for(Item i: i_list){
            if(i.returnCode().equals(code)){
                if(i.isAvailable(number)){
                    i.changeQuantity(1, number);
                    int index = this.getIndexInList(i.returnCode());
                    i_list.set(index-1, i);
                    System.out.println("Items Issued!");
                }
                else{
                    System.out.println("Item not available for issue, kindly re-stock!");
                }
            }
        }
    }

    // receive an item
    public void receive(int number, String code){
        for(Item i: i_list){
        if(i.returnCode().equals(code)){
                i.changeQuantity(0, number);
                int index = this.getIndexInList(i.returnCode());
                i_list.set(index-1, i);
                System.out.println("Items Received!");
            }
        }
    }

    // display on condition
    public void displayElementsWithMinimumPrice(int price){
        Scanner sc = new Scanner(System.in);
        int count = 0;
        for(Item i: i_list){
            if(i.returnRate() > price){
                count++;
            }
        }
        System.out.println("There are " + count + " items that match the criteria.");
        String isYes = "";
        System.out.println("Want to see details of items? (Yes/No)");
        isYes = sc.nextLine();
        if(isYes.equals("Yes")){
            for(Item i: i_list){
                if(i.returnRate() > price){
                    i.showData();
                }
            }
        }
        else return;
    }

    // utility functions

    // check if item is alreaady present
    public boolean isNamePresent(String temp){
        for(Item i: i_list){
            if(i.returnName().equals(temp))
                return true;
        }
        return false;
    }

    // check if code is in the list or not
    public boolean isCodePresent(String temp){
        for(Item i: i_list){
            if(i.returnCode().equals(temp))
                return true;
        }
        return false;
    }

    // get the index of item in the list
    public int getIndexInList(String code){
        if(code.charAt(code.length() - 2) == '0' ){
            char lastChar = code.charAt(code.length() - 1);
            return Character.getNumericValue(lastChar);
        }
        String temp = code.substring(4, 5);
        return Integer.parseInt(temp);
    }
    
    // change the quantity of the item
    public void changeQuantity(Item it){
        Scanner sc = new Scanner(System.in);
        System.out.println("Item Already Present. Do you want to update quantity? (Yes/No):");
        String temp = sc.nextLine();
        if(temp.equals("Yes")){
            System.out.println("Enter Amount of Items to be added: ");
            int i = sc.nextInt();
            sc.nextLine();
            it.changeQuantity(0, i);
            int index = this.getIndexInList(it.returnCode());
            i_list.set(index-1, it);
            System.out.println("Item Quantity Changed!");
        }
        
    }

    // this function reuturns the Item object if it is already present
    public Item replaceDuplicate(String name){
        for(Item i: i_list){
            if(i.returnName().equals(name)){
                return i;
            }
        }
        return null;
    }

}
