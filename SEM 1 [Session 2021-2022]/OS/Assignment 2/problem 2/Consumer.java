//package OS_Assignment_2;

public class Consumer implements Runnable{
    Buffer b;
    
    static int total;
    Consumer(Buffer bb)
    {
        b=bb;
        
    }
    public void run()
    {
        while(true) {
            if(Producer.runningProducers()==0&&b.isEmpty())
            {//System.out.println("Total value produced:"+Producer.getTotal());
            //System.out.println("Total value consumed:"+getTotal());
            System.out.println("Consumer thread finished");
            break;}
          try{
        
           int v=b.removeItem();
           if(v==-999) continue;
           System.out.println("Item ("+v+") removed from the buffer");
           //System.out.println("hello");
           total=total+v;
           
           Thread.sleep(1000);

          }catch(Exception e) {System.out.println(e.getMessage());}
        }
    }
    static int getTotal()
    {
        return total;
    }
}
