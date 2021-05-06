import java.util.Scanner;

class Date {  //class to store date (might use default class later)
    private int dd;
    private int mm;
    private int yy;
    public Date() {
        dd = -1; mm = -1; yy = -1;
    }
    public Date(Date D) {
        dd = D.dd; mm = D.mm; yy = D.yy;
    }
    public void getInput() {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter date in numbers: ");
        dd = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter month in numbers: ");
        mm = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter year in numbers: ");
        yy = sc.nextInt();
        sc.nextLine();
    }
    public String toString() {
        return (dd + "/" + mm + "/" + yy);
    }
    public int retDate() {
        return dd;
    }
    public int retMonth() {
        return mm;
    }
    public int retYear() {
        return yy;
    }
    public String retYearLast2Digs() { //return last 2 digits of the roll
        return String.valueOf(yy % 100);
    }
}

//stores student data
class Student {
    protected String roll;
    private String name;
    private String course;
    private Date admissionDate = new Date();  //instance of date class
    protected static final int n_subs = 5;
    protected int[] marks = null;
    static final int n_stud = 1000;
    static Student[] studentList = new Student[n_stud];
    static int studentsAdmitted = 0;
    public Student() {
        roll = null; name = null; course = null;
    }
    public boolean isEvaluated() {  //check presence of marks
        return (marks != null);
    }
    public Student(Student S) {  //construcctor
        roll = new String(S.roll);
        name = new String(S.name);
        course = new String(S.course);
        admissionDate = new Date(S.admissionDate);
    }
    public static Student search(String r) {  //search student by full roll
        for (int i = 0; i < studentsAdmitted; ++i) {
            if (studentList[i].roll.equals(r)) {
                return studentList[i];
            }
        }
        return null;
    }
    public static boolean remove(String r) {  //remove student
        int i;
        for (i = 0; i < studentsAdmitted; ++i) {
            if (studentList[i].roll.equals(r)) {
                break;
            }
        }
        if (i == studentsAdmitted) {
            return false;
        }
        for (; i < studentsAdmitted; ++i) {
            studentList[i] = studentList[i + 1];
        }
        studentList[i] = null;
        --studentsAdmitted;
        return true;
    } 
    public int getInput() {  //get input
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name: ");
        name = sc.nextLine();
        System.out.println("Enter Course: ");
        course = sc.nextLine();
        admissionDate.getInput();
        return 1;
    }
    private String getRollFormat(int r, int tot) {  //generate roll acc to format
        String temp = String.valueOf(r);
        String res = new String();
        for (int i = 0; i < (tot - temp.length()); ++i) {
            res += "0";
        }
        res += temp;
        return res;
    }
    public void admit(int nextRoll) {  //add student data in the list
        roll += admissionDate.retYearLast2Digs();
        roll += getRollFormat(nextRoll, 3);
        studentList[studentsAdmitted] = this;
        ++studentsAdmitted;
    }
    public void getMarks() {  //entry of marks
        Scanner sc = new Scanner(System.in);
        marks = new int[n_subs];
        System.out.println("Enter marks for 5 subjects: ");
        for (int i = 0; i < n_subs; ++i) {
            marks[i] = sc.nextInt();
            if(marks[i]>100){
                System.out.println("Marks Out Of Bounds!");
                return;
            }
            sc.nextLine();
        }
    }
    public int[] returnMarks() {
        return marks;
    }
    public String getRoll() {
        return roll;
    }
    public String getName() {
        return name;
    }
    int getTotalMarks() { //evaluate total marks
        if (marks == null)
            return -1;
        int sum = 0;
        for (int i = 0; i < n_subs; ++i) {
            sum += marks[i];
        }
        return sum;
    }
    public void showMarkSheet() { //marksheet of student
        System.out.println("\n******MARKSHEET******");
        System.out.println("---------------------");
        System.out.println("\nRoll: " + roll);
        System.out.println("Name: " + name);
        System.out.println("Course: " + course);
        System.out.println("Date of Admission: " + admissionDate);
        if (marks == null) {
            System.out.println("Marks not evaluated.");
            return;
        }
        System.out.println("Marks: ");
        for (int i = 0; i < n_subs; ++i) {
            System.out.println("Subject" + (i + 1) + ": " + marks[i]);
        }
        System.out.println("Total Marks: " + getTotalMarks());
    }
}

