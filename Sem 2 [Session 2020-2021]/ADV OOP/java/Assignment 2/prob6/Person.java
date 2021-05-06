import java.util.Scanner;

class Person{
    private String name;
    private Address address;
    private String phone;
    private Strg email;


    public Person(){
        name="";
        address = new Address();
        phone="";
        email="";
    }

    public void acceptData(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name:");
        name = sc.nextLine();
        System.out.println("Address:");
        address.acceptValues();
        System.out.println("Enter Phone:");
        phone = sc.nextLine();
        System.out.println("Enter Email-Id:");
        email = sc.nextLine();
    }

    public void displayData(){
        System.out.println("\nName: " + name);
        address.displayValues();
        System.out.println("Phone: " + phone);
        System.out.println("Email-Id: " + email);
    }

    public void changeAddress(int choice, String change){
        if(choice == 1){
            address.updatePremise(change);
        }
        else if(choice == 2){
            address.updateStreet(change);
        }
        else if(choice == 3){
            address.updateCity(change);
        }
        else if(choice == 4){
            address.updatePin(change);
        }
        else{
            address.updateState(change);
        }
    }

}