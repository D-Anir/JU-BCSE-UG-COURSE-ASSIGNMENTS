import java.util.*;

public class activities {
    static int menu() {
        System.out.println("\n**MENU**");
        System.out.println("1. Add Student.");
        System.out.println("2. Add Marks of Student.");
        System.out.println("3. Display MarkSheet of a Student");
        System.out.println("4. Display Number of Admitted Students.");
        System.out.println("5. Department RankList based on Marks.");
        System.out.println("6. Remove Student");
        System.out.println("7. Exit.");
        System.out.println("Enter Your choice: ");
        int choice;
        Scanner sc = new Scanner(System.in);
        choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }
    public static void main (String args[]) {
        Student S;
        //ararylist storing students of particular department
        ArrayList<ExtendedStudent>[] deptList = new ArrayList[DeptList.n_dept];
        for (int i = 0; i < DeptList.n_dept; ++i) {
            deptList[i] = new ArrayList<ExtendedStudent>();
        }
        ExtendedStudent tempE;
        int choice = 0;
        int idx = 0;
        String r;
        Scanner sc = new Scanner(System.in);
        while (choice != 7) {
            choice = menu();
            switch (choice) {
                case 1:
                    S = new ExtendedStudent();
                    idx = S.getInput();
                    S.admit(DeptList.getNextRoll(idx));
                    System.out.println("Your roll number is: " + S.getRoll()); //autognereted roll
                    tempE = new ExtendedStudent(S, idx);
                    deptList[idx - 1].add(tempE);
                    DeptList.updateDeptRoll(idx);
                    break;
                case 2:
                    System.out.println("Enter roll number: ");
                    r = sc.nextLine();
                    S = Student.search(r);
                    if (S == null) { //student not present
                        System.out.println("Invalid Roll Number.");
                    }
                    else {
                        S.getMarks();
                        idx = DeptList.getIndex(S.getRoll().substring(0, 4));
                        for (ExtendedStudent E : deptList[idx]) {
                            if (E.getRoll().equals(S.getRoll())) {
                                E.setMarks(S.returnMarks());
                                break;
                            }
                        }
                        System.out.println("Marks Added Successfully.");
                    }
                    break;
                case 3:
                    System.out.println("Enter roll number: ");
                    r = sc.nextLine();
                    S = Student.search(r);
                    if (S == null) {  //student not present
                        System.out.println("Invalid Roll Number.");
                    }
                    else {
                        S.showMarkSheet();
                    }
                    break;
                case 4:
                    System.out.println("Number of students taken admission: " + Student.studentsAdmitted);
                    break;
                case 5:
                    DeptList.showDeptList();
                    System.out.println("Choose the department: ");
                    idx = sc.nextInt();
                    sc.nextLine();
                    
                    Collections.sort(deptList[idx-1], ExtendedStudent.OnTotalMarks);
                    for (ExtendedStudent E : deptList[idx - 1]) {
                        if (E.isEvaluated()) {
                            System.out.println(E.getName() + ": " + E.getTotalMarks());
                        }
                        else{
                            System.out.println(E.getName() + ": Marks Not Entered Yet!");
                        }
                    }
                    break;
                case 6:
                    System.out.println("Enter roll number to be removed: ");
                    r = sc.nextLine();
                    S = Student.search(r);
                    if (S == null) {
                        System.out.println("Invalid Roll.");
                        break;
                    }
                    idx = DeptList.getIndex(S.getRoll().substring(0, 4));
                    tempE = new ExtendedStudent(S, idx);
                    int i = 0;
                    for (ExtendedStudent E : deptList[idx - 1]) {
                        if (E.equals(tempE)) {
                            break;
                        }
                        ++i;
                    }
                    deptList[idx - 1].remove(i);
                    Student.remove(r);
                    System.gc(); //garbage collector
                    S = null;
                    tempE = null;
                    System.gc();
                    System.out.println("Student removed!");
                    break;
                case 7:
                    break;
                default:
                    System.out.println("Invalid Choice!");
            }
        }
    }
}