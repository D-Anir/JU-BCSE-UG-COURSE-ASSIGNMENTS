import java.lang.Math;

public class QuoteOfTheDay {
    public static void main(String args[]){
        Quotes q = new Quotes();  //instance of class Quotes
        int length = q.quotes.length;  //stores length of hardcoded string array
        int index = (int)(Math.random()*(length+1));  //generated random integer between 0 and length
        System.out.println(q.quotes[index]);  //prints random string
    }
}
