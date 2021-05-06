public class DeptList {
    static int n_dept = 4;
    static String[] depts = {"Computer Science and Engineering",
                             "Electronics and Telecommunication Engineering",
                             "Chemical Engineering",
                             "Mechanical Engineering"};
    static String[] deptcodes = {"BCSE", "ETCE", "BCHE", "MECH"};
    static int[] deptAdmitted = new int[n_dept];
    
    public static void showDeptList() {
        System.out.println("Departments Available: ");
        for (int i = 0; i < n_dept; ++i) {
            System.out.println(String.valueOf(i + 1) + ". " + depts[i]);
        }
    }
    
    public static int getIndex(String deptcode) {
        for (int i = 0; i < n_dept; ++i) {
            if (deptcodes[i].equals(deptcode)) {
                return i + 1;
            }
        }
        return 0;
    }
    
    public static String getDept(int choice) {
        return depts[choice - 1];
    }
    public static String getDeptCode(int choice) {
        return deptcodes[choice - 1];
    }
    public static int getNextRoll(int choice) {
        return deptAdmitted[choice - 1] + 1;
    }
    public static void updateDeptRoll(int choice) {
        ++deptAdmitted[choice - 1];
    }
}