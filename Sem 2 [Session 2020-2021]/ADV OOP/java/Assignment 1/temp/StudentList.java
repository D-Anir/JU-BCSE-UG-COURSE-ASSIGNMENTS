public class StudentList {
    private DeptStudent[] list = new DeptStudent[100];
    private static int noOfStudents = 0;
    
    public StudentList(){
        for(int i = 0 ; i < 100 ; i++)
            list[i] = new DeptStudent();
    }

    public void addStudent(){
        if(noOfStudents >= 100){
            System.out.println("Maximum Student Reached!");
        }
        else{
            list[noOfStudents++].getData(noOfStudents);
        }
    }

    public void displayStudent(String r){
        for(int i=0 ; i < noOfStudents ; i++){
            if(r.equals(list[i].returnRoll()))
                list[i].showData();
        }
    }
}
