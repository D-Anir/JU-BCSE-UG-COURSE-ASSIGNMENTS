import java.io.*;
import java.util.*;

public class IndexingBook{
    
    public static void main(String args[]) throws IOException {
        File fobj = new File("test.txt");   //opening a file (creating if is not already present)
        Scanner sc = new Scanner(fobj);

        Map<String, List<Integer>> hm = new HashMap<>(); //HashMap to store <word, line numbers> pairs
        HashSet<String> uniqueWords;        //HashSet of strings to store unique words from each line
        String[] words;
        int line_number = 0;
        ArrayList<Integer> lines;        //array of integers to store line numbers of each unique word

        System.out.println();

        while(sc.hasNextLine()){
            line_number++;
            String line = sc.nextLine();
            words = line.split("\\s+|\\.");     //storing words of each line in an array

            uniqueWords = new HashSet<String>(Arrays.asList(words));
            for(String s : uniqueWords ){       //adding values to the hashMap
                if(hm.containsKey(s)){
                    hm.get(s).add(line_number);
                }
                else{
                    lines = new ArrayList<Integer>();
                    lines.add(line_number);
                    hm.put(s, lines);
                }
            }
        }

        //making a hashTable from the existing hashMap
        Hashtable<String, List<Integer>> HT = new Hashtable<String, List<Integer>>(hm);


        //sorting the keys in alphabetical order
        List<String> temp = Collections.list(HT.keys());
        Collections.sort(temp, String.CASE_INSENSITIVE_ORDER);
        Iterator<String> it = temp.iterator();

        while(it.hasNext()){
            String s = it.next();
            System.out.println(s + ": " + HT.get(s));
        }
        
        
    }

}