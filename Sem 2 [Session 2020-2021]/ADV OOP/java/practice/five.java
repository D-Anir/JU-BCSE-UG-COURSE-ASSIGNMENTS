import java.util.Scanner;

public class five {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter String: ");
        String s1;
        s1 = sc.nextLine();
        String s2 = s1;
        System.out.println(s1 == s1);
        System.out.println(s2.equals(s1));
        System.out.println("Enter First String: ");
        s1 = sc.nextLine();
        System.out.println("Enter Second String(equal to first string): ");
        s2 = sc.nextLine();
        System.out.println(s1 ==s2);
        System.out.println(s2.equals(s1));
        sc.close();
    }
}
