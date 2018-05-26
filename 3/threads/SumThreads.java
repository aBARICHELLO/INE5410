public class SumThreads extends Thread {
    static int counter = 0;

    @Override
    public void run() {
        for (int i = 0; i < 10; i++) {
            counter++;
        }
    }

    public static void main(String[] args) throws InterruptedException {
        SumThreads[] threadArray = new SumThreads[10];
        for (int i = 0; i < 10; i++) {
            threadArray[i] = new SumThreads();
            threadArray[i].start();
        }

        for (int i = 0; i < 10; i++) {
            threadArray[i].join();
        }
        System.out.println(counter);
    }
}