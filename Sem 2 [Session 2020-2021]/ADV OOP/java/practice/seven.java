// package practice;

import java.util.Scanner;

class seven {
    private int roll;
    String name;
    private int score;
    
    public seven(){

    }

    public seven(seven s){
        roll = s.roll;
        name = s.name;
        score = s.score;
    }

    public void setData(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Roll: ");
        roll = sc.nextInt();
        sc.nextLine();
        System.out.println("Enter Name: ");
        name = sc.nextLine();
        System.out.println("Enter Score: ");
        score = sc.nextInt();
        sc.close();
    }

    public void showData(){
        System.out.println(("Roll: "+roll));
        System.out.println(("Name: "+name));
        System.out.println(("Score: "+score));
    }
    public String toString(){
        return ("Roll: " + roll + "\nName: " + name + "\nScore: " + score);
    }
    public boolean equals(seven s){
        if(name.equals(s.name))
            return true;
        else return false;
    }
}
