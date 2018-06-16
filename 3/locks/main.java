package mypackage;

import mypackage.Crawler;


class Main {
    static String URL = "http://cco.inf.ufsc.br/";
    static int MAX_DEPTH = 200;
    static int MAX_VISIT_THREAD = 20;
    static int MAX_EXTRACT_THREAD = 2;

    public static void main(String[] args) {
        Crawler crawler = new Crawler();
        String content = crawler.downloadURL(URL);
        Queue<String> contentQueue = crawler.extractLinksFromURL(content);
        Queue<String> linkQueue = new LinkedList<String>();

        for (String r : contentQueue) {
            System.out.println(r);
        }
        System.out.println("\n--- Ended ---");
    }
}
