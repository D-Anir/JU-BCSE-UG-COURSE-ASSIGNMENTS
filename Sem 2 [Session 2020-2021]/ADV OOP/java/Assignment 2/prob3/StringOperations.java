import java.util.*;
import java.util.stream.*;

class StringOperations{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String input = "";
        
        System.out.println("\nEnter the String:");
        input = sc.nextLine();
        
        char arrayOfChars[] = input.replaceAll(" ", "").toCharArray();
        String arrayOfWords[] = input.split("\\s+|\\@|\\.");

        int choice = 0;
        
        while(choice != 6){
            choice = menu();
            switch(choice){
                case 1:
                    System.out.println("Number of a's : " + numberOfACharacter(arrayOfChars, 'a'));
                    System.out.println("Number of A's : " + numberOfACharacter(arrayOfChars, 'A'));
                    break;
                
                case 2:
                    System.out.print("Number of 'and's : " + numberOfAWord(arrayOfWords, "and"));
                    break;

                case 3:
                    if(input.startsWith("The", 0)){
                        System.out.println("Yes.");
                    }
                    else{
                        System.out.println("No.");
                    }
                    break;

                case 4:
                    System.out.println("Array of Characters:");
                    for(char c : arrayOfChars){
                        System.out.println(c);
                    }
                    break;

                case 5:
                    System.out.println("Array of Words(tokens):");
                    List<String> myStringList = new ArrayList<String>(arrayOfWords.length);
                    for (String s : arrayOfWords) {
                        myStringList.add(s);
                    }
                    
                    myStringList.removeAll(Collections.singleton(" "));
                    // arrayOfWords = myStringList.toArray(new String[0]);
                    
                    for(String s : myStringList){
                        System.out.println(s);
                    }
                    break;

                case 6:
                    System.exit(0);

                default:
                    System.out.println("Wrorng Choice!");
            }
        }
    }

    static int menu(){
        Scanner sc = new Scanner(System.in);
        System.out.println("\nMENU");
        System.out.println("1. Number of a's in the sting.");
        System.out.println("2. Number of 'and's in the string.");
        System.out.println("3. Does the string starts with 'The'?");
        System.out.println("4. Display string as Array of characters.");
        System.out.println("5. Display all words of the string.");
        System.out.println("6. Exit.");
        int choice;
        System.out.println("Enter Your Choice:");
        choice = sc.nextInt();
        sc.nextLine();
        return choice;
    }
    
    static int numberOfACharacter(char[] array, char ch){
        int count = 0;
        for(char c : array){
            if(c == ch){
                count++;
            }
        }
        return count;
    }

    static int numberOfAWord(String[] array, String word){
        int count = 0;
        for(String s : array){
            if(s.equals(word)){
                count++;
            }
        }
        return count;
    }


    
}