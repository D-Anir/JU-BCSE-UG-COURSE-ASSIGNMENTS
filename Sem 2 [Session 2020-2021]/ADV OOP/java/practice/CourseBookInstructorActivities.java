import java.util.*;

public class CourseBookInstructorActivities {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        Instructor i_list[] = new Instructor[100];
        TextBook tb_list[] = new TextBook[100];
        Course c_list[] = new Course[100];

        int i_count=0, t_count=0, c_count=0, ch=1, f=0;
        String b_name, c_name, i_name;

        while(true){
            System.out.println("\n***MENU***");
            System.out.println("1. Add Book.");
            System.out.println("2. Show Book");
            System.out.println("3. Add Instructor");
            System.out.println("4. Show Instructor");
            System.out.println("5. Add Course");
            System.out.println("6. Show Course");
            System.out.println("\nEnter Your Choice:");
            
            ch = sc.nextInt();
        
            switch(ch){
                case 1:
                    tb_list[t_count] = new TextBook();
                    tb_list[t_count].getInfo();
                    System.out.println(tb_list[t_count]);
                    t_count++;
                    break;

                case 2:
                    System.out.println("Enter Book Name:");
                    // sc.nextLine();
                    b_name = sc.nextLine();
                    f=0;
                    for(TextBook b:tb_list){
                        if(b.returnName() == b_name){
                            System.out.println(b);
                            f=1;
                        }
                    }
                    if(f==0)
                        System.out.println("Book does not exist!\n");
                    break;

                case 3:
                    i_list[i_count] = new Instructor();
                    i_list[i_count].getInfo();
                    i_count++;
                    break;

                case 4:
                    System.out.println("Enter Instructor Name:");
                    // sc.nextLine();
                    i_name = sc.nextLine();
                    f=0;
                    for(Instructor i:i_list){
                        if(i.returnName() == i_name){
                            System.out.println(i);
                            f=1;
                        }
                    }
                    if(f==0)
                        System.out.println("Instructor does not exist!\n");
                    break;

                case 5:
                    System.out.println("Enter Course Name:");
                    sc.nextLine();
                    c_name = sc.nextLine();
                    TextBook t_temp = new TextBook();
                    Instructor i_temp = new Instructor();

                    System.out.println("Enter Book Name:");
                    // sc.nextLine();
                    b_name = sc.nextLine();
                    f=0;
                    for(TextBook b:tb_list){
                        if(b.returnName() == b_name){
                            t_temp = b;
                            f=1;
                        }
                    }
                    if(f==0){
                        System.out.println("Book does not exist!\n");
                        break;
                    }

                    System.out.println("Enter Instructor Name:");
                    // sc.nextLine();
                    i_name = sc.nextLine();
                    f=0;
                    for(Instructor i:i_list){
                        if(i.returnName() == i_name){
                            i_temp = i;
                            f=1;
                        }
                    }
                    if(f==0){
                        System.out.println("Instructor does not exist!\n");
                        break;
                    }
                    
                    c_list[c_count] = new Course();
                    c_list[c_count] = new Course(c_name, i_temp, t_temp);
                    c_count++;

                    break;

                case 6:
                    System.out.println("Enter Course Name:");
                    // sc.nextLine();
                    c_name = sc.nextLine();
                    f=0;
                    for(Course c:c_list){
                        if(c.returnName() == c_name){
                            c.showDetails();
                            f=1;
                        }
                    }
                    if(f==0)
                        System.out.println("Course does not exist!\n");
                    break;
                
                default:
                    System.out.println("Wrong Choice!");
            }
            if(ch<0)
                break;
        }
        sc.close();
    }
}
