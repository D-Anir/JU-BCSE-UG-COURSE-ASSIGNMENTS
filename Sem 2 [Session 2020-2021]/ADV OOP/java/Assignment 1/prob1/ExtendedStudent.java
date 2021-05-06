import java.util.*;

class ExtendedStudent extends Student {
    private String dept;
    public ExtendedStudent() {
        super();
        dept = null;
    }
    public ExtendedStudent(Student S, int idx) {
        super(S);
        dept = new String(DeptList.getDept(idx));
    }
    @Override
    public int getInput() {
        super.getInput();
        DeptList.showDeptList();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Your Choice:");
        int choice = sc.nextInt();
        sc.nextLine();
        dept = DeptList.getDept(choice);
        roll = new String(DeptList.getDeptCode(choice));
        return choice;
    }
    public void setMarks(int m[]) {
        marks = new int[n_subs];
        for (int i = 0; i < n_subs; ++i) {
            marks[i] = m[i];
        }
    }
    public static final Comparator<ExtendedStudent> OnTotalMarks = new Comparator<ExtendedStudent>() {
        public int compare(ExtendedStudent a, ExtendedStudent b) {
            return Integer.compare(b.getTotalMarks(), a.getTotalMarks());
        }
    };
    public boolean equals(ExtendedStudent obj) {
        return roll.equals(obj.getRoll());
    }

}