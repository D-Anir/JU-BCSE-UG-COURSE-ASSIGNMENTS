import java.util.Scanner;

public class Student{
        private String roll;
        private String name;
        private String adm_date;
        private int marks[];
    
    public Student(){
        marks = new int[5];
    }

    public void getData(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Student Details:");
        System.out.print("Name: ");
        name = sc.nextLine();
        System.out.println("Marks in 5 subjects: ");
        for(int i=0 ; i<5 ; i++){
            marks[i] = sc.nextInt();
            sc.nextLine();
        }
        System.out.println("\nAdmission Date: ");
        adm_date = sc.nextLine();

        sc.close();
    }

    public void assignRoll(String course, String r){
        if(r.length()!=2)
            roll = course + adm_date + "00" + r;
        else    
            roll = course + adm_date + "0" + r;
    }

    public void showData(){
        System.out.println("Roll: " + roll);
        System.out.println("Name: " + name);
        System.out.println("Admission Date: " + adm_date);
        System.out.println(".......................");
        System.out.println("Marks");
        System.out.println(".......................");
        for(int i=0 ; i<5 ; i++)
            System.out.println("Subject " + i + "\t" + marks[i]);
    }

    public String returnRoll(){
        return roll;
    }

}