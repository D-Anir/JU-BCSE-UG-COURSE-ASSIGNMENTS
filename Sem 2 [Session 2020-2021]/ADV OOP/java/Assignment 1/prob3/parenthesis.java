import java.util.Scanner;

public class parenthesis {
    
    public static void main(String args[]){
        String expression;
        Scanner sc = new Scanner(System.in);
        System.out.println("\nEnter the expression to be checked: ");  //takes expression with parenthesis
        expression = sc.nextLine();

        if(isBalanced(expression))
            System.out.println("TRUE (The expression is balanced!)");
        else
            System.out.println("FALSE (The expression is not balanced!)");

        sc.close();
    }

    //function returns true if the expression is balanced
    public static boolean isBalanced(String exp){  
        
        my_stack s = new my_stack(exp.length());
        char present_char, popped_char;

        for(int i = 0 ; i < exp.length() ; i++){
            
            present_char = exp.charAt(i);
            if(present_char == '(' || present_char == '{' || present_char == '[' ){  //adds if opening bracket is encountered
                s.push(present_char);
                continue;
            }

            if(s.isEmpty())
                return false;

            popped_char = s.pop();

            switch(present_char){
                case ')':
                    if(popped_char == '}' || popped_char == ']')
                        return false;
                    break;
                
                case '}':
                    if(popped_char == ']' || popped_char == ')')
                        return false;
                    break;

                case ']':
                    if(popped_char == '}' || popped_char == ')')
                        return false;
                    break;
            }            
        }

        return s.isEmpty();

    }

}
