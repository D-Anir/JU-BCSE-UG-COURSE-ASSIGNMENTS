public class ThreadOperations{

	public static void main(String args[]) throws InterruptedException {
		ProducerConsumer pc = new ProducerConsumer();

		// producer
		Thread t1 = new Thread(new Runnable(){
			@Override
			public void run(){
				try{
					pc.produce();
				} catch(InterruptedException e){
					e.printStackTrace();
				}
			}
		});

		// consumer
		Thread t2 = new Thread(new Runnable(){
			@Override
			public void run(){
				try{
					pc.consumer();
				} catch(InterruptedException e){
					e.printStackTrace();
				}
			}
		});

		// start threads
		t1.start();
		t2.start();

		// t1 stops before t2
		t1.join();
		t2.join();
	}
}