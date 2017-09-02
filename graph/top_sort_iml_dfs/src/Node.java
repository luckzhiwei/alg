import java.util.ArrayList;

/**
 * Created by zhiwei on 2017/9/2.
 */
public class Node {
    public int number;
    public ArrayList<Node> mAdjs = new ArrayList<>();
    public int color;
    public int fVisitTime;
    public int sVisitTime;

    public static int WHITE = 0;
    public static int GRAY = 1;
    public static int BLACK = 2;

    public Node(int number) {
        this.color = WHITE;
        this.number = number;
    }

    public void addNode(Node node) {
        this.mAdjs.add(node);
    }
}
