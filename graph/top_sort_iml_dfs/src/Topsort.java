import java.util.ArrayList;

/**
 * Created by zhiwei on 2017/9/2.
 */
public class Topsort {

    private ArrayList<Node> mGraph;
    private int time;

    public Topsort() {
        this.mGraph = new ArrayList<>();
    }

    public void topSort() {
        this.dfs();
        this.mGraph.sort((node1, node2) -> node2.fVisitTime - node1.fVisitTime);
    }

    public void dfs() {
        for (Node node : this.mGraph) {
            if (node.color == Node.WHITE) {
                this.dfsVisit(node);
            }
        }
    }

    public void dfsVisit(Node node) {
        node.color = Node.GRAY;
        node.sVisitTime = ++this.time;
        for (Node adjNode : node.mAdjs) {
            if (adjNode.color == Node.WHITE) {
                dfsVisit(adjNode);
            }
        }
        node.color = Node.BLACK;
        node.fVisitTime = ++this.time;
    }

    public static void main(String[] args) {
        Node node1 = new Node(1);
        Node node2 = new Node(2);
        node1.addNode(node2);
        Topsort ts = new Topsort();
        ts.mGraph.add(node2);
        ts.mGraph.add(node1);
        ts.topSort();
        for (Node node : ts.mGraph) {
            System.out.println("node number is " + node.number);
        }
    }
}
