//package OS_Assignment_2;

public class Producer implements Runnable{
    Buffer b;
    int id;
    static int n;
    public static int p;
    static int tot;

    Producer(Buffer bb)
    {
        b=bb;
        id=n+1;
        n++;
    }
    public void run()
    {
        for(int i=0;i<10;i++){
        int x=(int)(100*Math.random()+1);
        Item it=new Item(id,x);
        
        b.addItem(it);
        System.out.println("Producer "+id+" adds value "+x+" to the shared buffer");
        tot=tot+x;
        
        try{
        Thread.sleep(1000);
        }catch(Exception e) {}
        }
        p--;
    }
    static int runningProducers()
    {
        return p;
    }
    static int getTotal()
    {
        return tot;
    }
}
