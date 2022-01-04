
import java.util.Scanner;
public class ProducerConsumer {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of producers");
        int p=sc.nextInt();
        System.out.println("Enter the number of consumers");
        int c=sc.nextInt();
        Buffer b=new Buffer();
        Producer ps[]=new Producer[p];
        Consumer cs[]=new Consumer[c];
        Thread prods[]=new Thread[p];
        Thread cons[]=new Thread[c];
        for(int i=0;i<p;i++)
        {
            ps[i]=new Producer(b);
            prods[i]=new Thread(ps[i]);
        }
        Producer.p =p;
        for(int i=0;i<c;i++)
        {
            cs[i]=new Consumer(b);
            cons[i]=new Thread(cs[i]);
        }
        for(int i=0;i<p;i++)
        {
            prods[i].start();
        }
        for(int i=0;i<c;i++)
        {
            cons[i].start();
        }
        for(int i=0;i<10000;i++);
        while(true)
        {
            //System.out.println("in loop in main");
            for(int j=0;j<10000;j++);
            if(b.isEmpty()&&Producer.p==0)  break;
        }
        System.out.println("Total value produced: "+Producer.getTotal());
        System.out.println("Total value consumed: "+Consumer.getTotal());
        sc.close();
    }
}
