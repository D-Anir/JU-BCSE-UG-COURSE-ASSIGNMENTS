import java.util.Scanner;

class Wrapper {
    public static void main(String args[]){
        
        // basic type to wrapper class object
        int i1 = 10;
        Integer a1 = Integer.valueOf(i1); //explicitly
        Integer j1 = a1;                  //autoboxing
        System.out.println("Output (i): " + a1 + " " + j1);

        
        // wrapper class object to basic type
        // unboxing
        Integer a2 = new Integer(5);
        int i2 = a2.intValue();         //explicitly
        int j2 = a2;                    //unboxing
        System.out.println("Output (ii): " + a2 + " " + j2);


        // basic type to String
        int i3 = 9;
        String s1 = Integer.toString(i3);
        System.out.println("Output (iii): " + i3 + " " + s1);


        // String to wrapper class object
        String s2 = "15";
        Integer a3 = new Integer(s2);
        System.out.println("Output (iv): " + s2 + " " + a3);


        // wrapper class object to String
        Integer a4 = new Integer(45);
        String s3 = Integer.toString(a4);
        System.out.println("Output (v): " + a4 + " " + s3);
    }
}