public class HiloParImpar implements Runnable {
    //Atributos
    private int numhilo;
 
    //Constructor
    public HiloParImpar(int numhilo) {
        this.numhilo = numhilo;
    }
     
    public void run() {
         
            //Segun el tipo hace una u otra cosa
            switch (numhilo) {
                case 1:
                    for (int i = 1; i <=100; i++) {
						if ( i%2==0)
                         System.out.println("HILO "+Thread.currentThread().getId()+" generando número "+i);
                    }
                    break;
                case 2:
                    
                    for (int i = 101; i <=200; i++) {
						  if ( i%2==1)
                          System.out.println("HILO "+Thread.currentThread().getId()+" generando número "+i);

                    }
                    break;
                     
            				}
 
        }
         
        

 
    public static void main(String[] args) {
         
         
         
        HiloParImpar h1 = new HiloParImpar(1);
        HiloParImpar h2 = new HiloParImpar(2);
        
        
         Thread t1 = new Thread(h1);
        Thread t2 = new Thread(h2);

        // Start the threads
        t1.start();
        t2.start();
         
    }
 
}
