import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;
import org.jsoup.select.Elements;
import org.jsoup.helper.Validate;
import java.util.LinkedList;
import java.util.Queue;


class Main {
    public static void main(String[] args) {
        Crawler crawler = new Crawler();
        Queue<String> results = crawler.extractLinksFromURL("http://cco.inf.ufsc.br/");
        for (String r : results) {
            System.out.println(r);
        }
        System.out.println("lol");
    }
}

class Crawler {
    public String downloadURL(String url) {
        try {
            String document = Jsoup.connect(url).get().html();
            return document;
        } catch (Throwable e) {
            e.printStackTrace();
            return null;
        }
    }

    public Queue<String> extractLinksFromURL(String url) {
        Queue<String> queue = new LinkedList<String>();
        Document doc = Jsoup.parse(url);
        Elements links = doc.select("a[href]");
        for (Element link : links) {
            String suburl = link.attr("abs:href");
            if (suburl.length() > 0 && suburl.startsWith("http")) {
                queue.add(url);
            }
        }
        return queue;
    }
}
