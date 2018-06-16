import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.jsoup.helper.Validate;
import java.util.LinkedList;
import java.util.Queue;


// VISITOR = dequeue from linkQueue, download it and add to htmlQueue
// EXTRACTOR = dequeue htmlQueue, extract and save links, add links to linkQueue

class Main {
    static String URL = "http://cco.inf.ufsc.br/";
    static int MAX_DEPTH = 200;
    static int MAX_VISITOR_THREADS = 20;
    static int MAX_EXTRACTOR_THREADS = 2;

    public static void main(String[] args) {
        Queue<String> linkQueue = new LinkedList<String>();
        Queue<String> htmlQueue = new LinkedList<String>();
        linkQueue.add(URL);

        VisitorThread[] visitorThreads = new VisitorThread[MAX_VISITOR_THREADS];
        ExtractorThread[] extractorThreads = new ExtractorThread[MAX_EXTRACTOR_THREADS];

        for (int i = 0; i < MAX_VISITOR_THREADS; i++) {
            visitorThreads[i] = new VisitorThread();
            visitorThreads[i].start();
        }
        for (int i = 0; i < MAX_EXTRACTOR_THREADS; i++) {
            extractorThreads[i] = new ExtractorThread();
            extractorThreads[i].start();
        }

        try {
            for (int i = 0; i < MAX_VISITOR_THREADS; i++) {
                visitorThreads[i].join();
            }
            for (int i = 0; i < MAX_EXTRACTOR_THREADS; i++) {
                extractorThreads[i].join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("--- Ended ---");
    }
}

class Crawler {
    public String downloadHTML(String URL) {
        try {
            String document = Jsoup.connect(URL).get().html();
            return document;
        } catch (Throwable e) {
            e.printStackTrace();
            return null;
        }
    }

    public Queue<String> extractLinksFromURL(String content) {
        Queue<String> queue = new LinkedList<String>();
        Document doc = Jsoup.parse(content);
        Elements links = doc.select("a");
        for (Element link : links) {
            String subURL = link.attr("abs:href");
            if (subURL.length() > 0 && subURL.startsWith("http")) {
                queue.add(subURL);
            }
        }
        return queue;
    }
}

class VisitorThread extends Thread {

}

class ExtractorThread extends Thread {

}
