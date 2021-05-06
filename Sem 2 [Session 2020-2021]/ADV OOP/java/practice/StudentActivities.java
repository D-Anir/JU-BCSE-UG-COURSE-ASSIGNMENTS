// package practice;

class StudentActivities {
    public static void main(String args[]){
        seven s1;
        s1 = new seven();
        s1.setData();
        seven s2 = new seven(s1);
        System.out.println(s2);
        if(s1.equals(s2))
            System.out.println("EQUAL!");
    }
}