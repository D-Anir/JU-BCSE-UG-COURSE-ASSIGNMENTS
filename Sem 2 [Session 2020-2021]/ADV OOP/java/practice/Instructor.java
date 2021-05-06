import java.util.Scanner;

public class Instructor {
    private String name;
    private String phone;

    public Instructor(){

    }

    public Instructor(Instructor i){
        name = i.name;
        phone = i.phone;
    }

    public void getInfo(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Instructor Name: ");
        name = sc.nextLine();
        System.out.println("Enter Phone No.: ");
        phone = sc.nextLine();
        sc.close();
    }

    public String toString(){
        return ("Name: " + name + "\nPhone: " + phone);
    }

    public String returnName(){
        return name;
    }

}

