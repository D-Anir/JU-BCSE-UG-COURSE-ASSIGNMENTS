import java.util.Scanner;

public class activities {
    public static void main(String args[]) {
        StudentList sl = new StudentList();

        int choice;
        String roll;
        Scanner sc = new Scanner(System.in);
        System.out.println("1. Add Student.\n");
        System.out.println("2. Display Student.\n");
        System.out.println("3. Exit.\n");
        System.out.print("Enter Your Choice: ");
        choice = sc.nextInt();
        switch(choice){
            case 1:
                sl.addStudent();
                break;
            case 2:
                System.out.print("\nEnter Roll: ");
                roll = sc.nextLine();
                sl.displayStudent(roll);
                break;
            default:
                System.out.println("Wrong Choice!");
        }
        sc.close();
    }
}
