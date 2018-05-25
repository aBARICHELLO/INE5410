import java.io.*;

public class FileThread extends Thread {
    String targetName;

    public FileThread(String path, String targetName) {
        this.targetName = targetName;
        this.search(path);
        System.out.println("Thread at path: " + path);
    }

    public void search(String path) {
        File rootPath = new File(path);
        checkFileExists(rootPath);
        String[] files = rootPath.list();
        for (String subfileName : files) {
            File subfile = new File(subfileName);
            if (subfile.isDirectory()) {
                System.out.println("Directory " + subfileName);
                FileThread thread = new FileThread(subfile.getName(), targetName);
                thread.start();
            } else {
                if (subfile.getName().equals(targetName)) {
                    System.out.println("Found at ");
                }
            }
        }
    }

    public void checkFileExists(File path) {
        if (path.exists()) {
            return;
        }
        System.exit(0);
    }
}
