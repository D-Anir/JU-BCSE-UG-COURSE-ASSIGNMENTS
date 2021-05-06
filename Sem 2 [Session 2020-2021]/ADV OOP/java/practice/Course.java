public class Course {
    private String name;
    private Instructor i;
    private TextBook tb;

    public Course(){
        
    }

    public Course(String s, Instructor in, TextBook t){
        name = s;
        i = new Instructor(in);
        tb = new TextBook(t);
    }

    // public void getInfo(){
    //     Scanner sc = new Scanner(System.in);
    //     System.out.println("Enter Course Title: ");
    //     name = sc.nextLine();

    //     System.out.println("Enter Instuctor Details: ");
    //     i.getInfo();
    //     System.out.println("Enter Textbook Details: ");
    //     tb.getInfo();
    //     sc.close();
    // }

    public void showDetails(){
        System.out.println("Name: " + name);
        System.out.println("Instructor Details:\n");
        System.out.println(i);
        System.out.println("TextBook Details:\n");
        System.out.println(tb);
    }

    public String returnName(){
        return name;
    }
}

