class Run {
    public static void main(String[] args) {
        NamedThread nt;
        if (args.length == 0) {
            nt = new NamedThread();
        } else {
            nt = new NamedThread(args[0]);
        }
        nt.start();
    }
}

class NamedThread extends Thread {
    NamedThread() {}

    NamedThread(String name) {
        super(name);
    }

    public void run() {
        System.out.println("Thread name: " + getName());
    }
}
