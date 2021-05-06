import java.util.Scanner;

public class Address {
    private String premiseNo;
    private String street;
    private String city;
    private String pin;
    private String state;


    public void acceptValues(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Premise Number:");
        premiseNo = sc.nextLine();
        System.out.println("Enter Street:");
        street = sc.nextLine();
        System.out.println("Enter City:");
        city = sc.nextLine();
        System.out.println("Enter Pin:");
        pin = sc.nextLine();
        System.out.println("Enter State:");
        state = sc.nextLine();
    }

    public void displayValues(){
        System.out.println("Address: " + premiseNo + ", " + street + ", " + city + ", " + state + "-" + pin);      
    }

    public void updatePremise(String temp){
        premiseNo = temp;
    }
    public void updateStreet(String temp){
        street = temp;
    }
    public void updateCity(String temp){
        city = temp;
    }
    public void updatePin(String temp){
        pin = temp;
    }
    public void updateState(String temp){
        state = temp;
    }
}
