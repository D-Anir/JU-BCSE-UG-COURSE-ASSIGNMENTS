import java.util.Scanner;
import java.util.ArrayList;

class Institute {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        ArrayList<Student> s_list = new ArrayList<>();
        ArrayList<Faculty> f_list = new ArrayList<>();
        
        Faculty ft;
        Student st;

        int choice = 0, sub_choice1 = 0, sub_choice2 = 0, index;
        String id, change;
        while(choice != 5){
            choice = menu();
            switch(choice){
                case 1:
                    ft = new Faculty();
                    ft.acceptData(f_list.size() + 1);
                    f_list.add(ft);
                    break;
                
                case 2:
                    st = new Student();
                    st.acceptData(s_list.size() + 1);
                    s_list.add(st);
                    break;
                
                case 3:
                    if(f_list.size() == 0 && s_list.size() == 0){
                        System.out.println("No Student or Faculty Added!");
                        break;
                    }
                    sub_choice1 = sub_menu1();
                    switch(sub_choice1){
                        case 1:
                            System.out.println("Enter Employee ID:");
                            id = sc.nextLine();
                            index = isFaccultyPresent(f_list, id);
                            if(index != -1){
                                f_list.get(index).displayData();
                            }
                            else{
                                System.out.println("Faculty Not Present!");
                                break;
                            }
                            break;

                        case 2:
                            System.out.println("Enter Roll Number:");
                            id = sc.nextLine();
                            index = isStudentPresent(s_list, id);
                            if(index != -1){
                                s_list.get(index).displayData();
                            }
                            else{
                                System.out.println("Student Not Present!");
                                break;
                            }
                            break;

                        default:
                            System.out.println("Wrong Choice!");
                    }
                    break;

                case 4:
                    if(f_list.size() == 0 && s_list.size() == 0){
                        System.out.println("No Student or Faculty Added!");
                        break;
                    }
                    sub_choice1 = sub_menu1();
                    switch(sub_choice1){
                        case 1:
                            System.out.println("Enter Employee ID:");
                            id = sc.nextLine();
                            index = isFaccultyPresent(f_list, id);
                            if(index != -1){
                                while(sub_choice2 != 6){  
                                    sub_choice2 = sub_menu2();
                                    switch(sub_choice2){
                                        case 1:
                                            System.out.println("Enter New Premise No.:");
                                            change = sc.nextLine();
                                            f_list.get(index).changeAddress(sub_choice2, change);
                                            System.out.println("Premise Changed!");
                                            break;
                                        
                                        case 2:
                                            System.out.println("Enter New Street:");
                                            change = sc.nextLine();
                                            f_list.get(index).changeAddress(sub_choice2, change);
                                            System.out.println("Street Changed!");
                                            break;

                                        case 3:
                                            System.out.println("Enter New City:");
                                            change = sc.nextLine();
                                            f_list.get(index).changeAddress(sub_choice2, change);
                                            System.out.println("City Changed!");
                                            break;

                                        case 4:
                                            System.out.println("Enter New Pin:");
                                            change = sc.nextLine();
                                            f_list.get(index).changeAddress(sub_choice2, change);
                                            System.out.println("Premise Changed!");
                                            break;
                                        
                                        case 5:
                                            System.out.println("Enter New State:");
                                            change = sc.nextLine();
                                            f_list.get(index).changeAddress(sub_choice2, change);
                                            System.out.println("State Changed!");
                                            break;

                                        case 6:
                                            break;
                                        
                                        default:
                                            System.out.println("Wrong Choice!");
                                    }
                                }
                            }
                            else{
                                System.out.println("Faculty Not Present!");
                                break;
                            }
                            break;

                        case 2:
                            System.out.println("Enter Roll Number:");
                            id = sc.nextLine();
                            index = isStudentPresent(s_list, id);
                            if(index != -1){
                                while(sub_choice2 != 6){  
                                    sub_choice2 = sub_menu2();
                                    switch(sub_choice2){
                                        case 1:
                                            System.out.println("Enter New Premise No.:");
                                            change = sc.nextLine();
                                            s_list.get(index).changeAddress(sub_choice2, change);
                                            System.out.println("Premise Changed!");
                                            break;
                                        
                                        case 2:
                                            System.out.println("Enter New Street:");
                                            change = sc.nextLine();
                                            s_list.get(index).changeAddress(sub_choice2, change);
                                            System.out.println("Street Changed!");
                                            break;

                                        case 3:
                                            System.out.println("Enter New City:");
                                            change = sc.nextLine();
                                            s_list.get(index).changeAddress(sub_choice2, change);
                                            System.out.println("City Changed!");
                                            break;

                                        case 4:
                                            System.out.println("Enter New Pin:");
                                            change = sc.nextLine();
                                            s_list.get(index).changeAddress(sub_choice2, change);
                                            System.out.println("Premise Changed!");
                                            break;
                                        
                                        case 5:
                                            System.out.println("Enter New State:");
                                            change = sc.nextLine();
                                            s_list.get(index).changeAddress(sub_choice2, change);
                                            System.out.println("State Changed!");
                                            break;

                                        case 6:
                                            break;
                                        
                                        default:
                                            System.out.println("Wrong Choice!");
                                    }
                                }

                            }
                            else{
                                System.out.println("Student Not Present!");
                                break;
                            }
                            break;

                        default:
                            System.out.println("Wrong Choice!");
                    }
                    break;

                case 5:
                    System.exit(0);

                default:
                    System.out.println("Wrong Choice!");
            }
        }

    }

    static int menu(){
        Scanner sc = new Scanner(System.in);
        System.out.println("\n****INSTITUTE MANAGEMENT SYSTEM****");
        System.out.println("1. Add Faculty.");
        System.out.println("2. Add Student.");
        System.out.println("3. Display Details.");
        System.out.println("4. Change Address of a Person.");
        System.out.println("5. Exit.");
        System.out.println("Enter Your Choice:");
        int choice;
        choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }

    static int sub_menu1(){
        Scanner sc = new Scanner(System.in);
        System.out.println("\n1. Faculty.");
        System.out.println("2. Student.");
        System.out.println("Enter Your Choice: ");
        int choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }

    static int sub_menu2(){
        Scanner sc = new Scanner(System.in);
        System.out.println("\n1. Premise Number.");
        System.out.println("2. Street.");
        System.out.println("3. City.");
        System.out.println("4. Pin.");
        System.out.println("5. State.");
        System.out.println("6. Exit.");
        System.out.println("Enter Your Choice: ");
        int choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }

    static int isStudentPresent(ArrayList<Student> list, String id){
        int index = 0;
        for(Student ft : list){
            if(ft.returnRoll().equals(id))
                return index;
            index++;
        }
        return -1;
    }

    static int isFaccultyPresent(ArrayList<Faculty> list, String id){
        int index = 0;
        for(Faculty ft : list){
            if(ft.returnID().equals(id))
                return index;
            index++;
        }
        return -1;
    }
}
