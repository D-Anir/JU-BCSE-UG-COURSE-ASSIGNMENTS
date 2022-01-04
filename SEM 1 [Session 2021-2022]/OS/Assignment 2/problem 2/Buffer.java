//package OS_Assignment_2;

class Item
{
    int pid;
    int val;
    Item(int pi, int v)
    {
        pid=pi;
        val=v;
    }
    int getVal()
    {
        return val;
    }
    int getPID()
    {
        return pid;
    }
}
public class Buffer {
    Item buffer[]=new Item[50];
    int i,j;
    int n;
    Buffer()
    {
        i=0;
        j=0;
        n=0;
    }
    synchronized void addItem(Item it)
    {
        while(isFull())
        {
            try{
                wait();
            }catch(Exception e) { System.out.println(e.getMessage());}
        }
        buffer[i]=it;
        i=(i+1)%50;
        n++;
        notifyAll();
    }
    boolean isFull()
    {
        return n==50;
    }
    boolean isEmpty()
    {
        return n==0;

    }
    synchronized int removeItem()throws InterruptedException
    {
        while(isEmpty())
        {
            if(Producer.p==0) return -999;
            try{
                wait();
            }catch(Exception e) { System.out.println(e.getMessage());}
        }
        
        int v=buffer[j].getVal();
        n--;
        j=(j+1)%50;
        notifyAll();
        return v;
    }
}
