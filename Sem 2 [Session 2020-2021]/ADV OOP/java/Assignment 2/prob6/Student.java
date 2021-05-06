import java.util.Scanner;

class Student extends Person {
    private String roll;
    private String course;

    public Student(){
        super();
        roll = "";
        course = "";
    }

    public void acceptData(int id){
        super.acceptData();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Course of Study:");
        course = sc.nextLine();
        roll = this.generateRoll(id);
        System.out.println("Auto-generated Roll: " + roll);
    }

    public void displayData(){
        super.displayData();
        System.out.println("Roll Number: " + roll);
        System.out.println("Course of Study: " + course);
    }

    public String generateRoll(int id){
        return "100" + String.valueOf(id);
    }

    public String returnRoll(){
        return roll;
    }
}
