import java.io.*;

public class Main {
    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Use java Main path fileName");
        }
        String path = args[0];
        String targetName = args[1];

        FileThread ft = new FileThread(path, targetName);
        ft.start();
    }
}
