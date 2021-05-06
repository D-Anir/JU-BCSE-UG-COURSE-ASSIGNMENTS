import java.util.Scanner;

public class TextBook {
    private String title;
    private String author;
    private String publisher;

    public TextBook(){

    }

    public TextBook(TextBook t){
        title = t.title;
        author = t.author;
        publisher = t.publisher;
    }

    public void getInfo(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter TextBook Title: ");
        title = sc.nextLine();
        System.out.println("Enter TextBook Author: ");
        author = sc.nextLine();
        System.out.println("Enter Textbook Publisher: ");
        publisher = sc.nextLine();
        sc.close();
    }

    public String toString(){
        return ("Title: " + title + "\nAuthor: " + author + "\nPublisher: " + publisher);
    }

    public String returnName(){
        return title;
    }

}

