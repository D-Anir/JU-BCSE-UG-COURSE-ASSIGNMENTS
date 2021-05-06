import java.util.Scanner;

public class DeptStudent extends Student {
    
    private String course = "";

    public DeptStudent(){

    }

    public void getData(int nos){
        super.getData();
        Scanner sc = new Scanner(System.in);

        System.out.println("Course: ");
        course = sc.nextLine();
        
        super.assignRoll(course, String.valueOf(nos));
        sc.close();
    }

    public void showData(){
        super.showData();
        System.out.print("Course: " + course);
    }
}
