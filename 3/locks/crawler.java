import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.jsoup.helper.Validate;
import java.util.LinkedList;
import java.util.Queue;


class Main {
    static String URL = "http://cco.inf.ufsc.br/";
    static int MAX_DEPTH = 200;

    public static void main(String[] args) {
        Crawler crawler = new Crawler();
        String content = crawler.downloadURL(URL);
        Queue<String> results = crawler.extractLinksFromURL(content);

        for (String r : results) {
            System.out.println(r);
        }
        System.out.println("--- Ended ---");
    }
}

class Crawler {
    public String downloadURL(String URL) {
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
