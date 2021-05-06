import java.util.Scanner;

class Faculty extends Person{
    private String empId;
    private String dept;
    private String specialisation;

    public Faculty(){
        super();
        empId = "";
        dept = "";
        specialisation = "";
    }

    public void acceptData(int id){
        super.acceptData();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Department:");
        dept = sc.nextLine();
        System.out.println("Enter Specialisation:");
        specialisation = sc.nextLine();
        empId = this.generateID(id);
        System.out.println("Auto-generated Employee ID: " + empId);
    }

    public void displayData(){
        super.displayData();
        System.out.println("Employee ID: " + empId);
        System.out.println("Department: " + dept);
        System.out.println("Specialiastion: " + specialisation);
    }

    public String generateID(int id){
        return "100" + String.valueOf(id);
    }

    public String returnID(){
        return empId;
    }
}
