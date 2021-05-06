import java.util.LinkedList;

public class ProducerConsumer {
    LinkedList<Integer> list = new LinkedList<Integer>();
    int capacity = 2;

    public ProducerConsumer(){
        // constructor
    }

    // producer thread
    public void produce() throws InterruptedException{
        int value = 0;
        System.out.println();
        while(true){
            synchronized(this){

                // if queue list is full, the producer waits
                while( capacity == list.size() ){
                    wait();
                }

                // if list not full, produce queues
                System.out.println("Producer produced Queue: " + value);
                list.add(value++);

                // consumer can now start consuming, as the list is not empty
                notifyAll();

                // for smooth debuging
                Thread.sleep(1000);
            }
        }
    }

    public void consumer() throws InterruptedException{
        int value = 0;
        System.out.println();
        while(true){
            synchronized(this){

                // if the list is empty, the consumer awaits
                while( list.size() == 0 ){
                    wait();
                }

                // if list not empty, consume queues
                value = list.removeFirst();
                System.out.println("Consumer Consumed Queue: " + value);

                // producer can now produce as list is not full
                notifyAll();

                // for smooth debuging
                Thread.sleep(2500);
            }
        }
    }
}
