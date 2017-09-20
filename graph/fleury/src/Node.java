import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

/**
 * Created by zhiwei on 2017/9/10.
 */
public class Node {
    public int number;
    public ArrayList<Integer> mAdjs = new ArrayList<>();


    public static class Egde {
        public int number;
        public boolean hasVisisted;

        public Egde(int number) {
            this.number = number;
            this.hasVisisted = false;
        }
    }

    public Node(int number) {
        this.number = number;
    }

}
