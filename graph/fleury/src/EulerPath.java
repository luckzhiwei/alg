import java.util.*;

/**
 * Created by zhiwei on 2017/9/10.
 */
public class EulerPath {

    private ArrayList<Node> graph;
    private Stack<Integer> stack;
    private String info;
    private int totalDegree = 0;


    public EulerPath(int size) {
        this.graph = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            this.graph.add(new Node(i));
        }
        this.stack = new Stack<>();
    }

    public void parseString(String info) {
        int start = info.charAt(0) - 0x30;
        int end = info.charAt(2) - 0x30;
        this.graph.get(start - 1).mAdjs.add(end - 1);
        this.graph.get(end - 1).mAdjs.add(start - 1);
    }

    public boolean eulerDfs(int num) {
        this.stack.push(num);
        Node node = this.graph.get(num);
        if (node.mAdjs.size() == 0 && this.totalDegree != 0) {
            this.stack.pop();
            return false;
        }
        for (int i = 0; i < node.mAdjs.size(); i++) {
            int adjNodeNum = node.mAdjs.get(i);
            Node nodeAdj = this.graph.get(adjNodeNum);
            node.mAdjs.remove(i);
            Iterator<Integer> iterator = nodeAdj.mAdjs.iterator();
            for (; iterator.hasNext(); ) {
                if (iterator.next() == num) {
                    iterator.remove();
                    break;
                }
            }
            this.totalDegree -= 2;
            if (!this.eulerDfs(adjNodeNum)) {
                node.mAdjs.add(adjNodeNum);
                nodeAdj.mAdjs.add(num);
                this.totalDegree += 2;
                continue;
            }
        }
        return true;
    }

    public void fluery() {
        for (Node node : graph) {
            if ((node.mAdjs.size() & 1) != 0) {
                System.out.println("no eluar path");
                return;
            } else {
                this.totalDegree += node.mAdjs.size();
            }
        }
        eulerDfs(0);
    }

    public void printPath() {
        for (int num : this.stack) {
            System.out.print(num + "-->");
        }
    }


    public static void main(String args[]) {
        EulerPath eulerPath = new EulerPath(9);
        eulerPath.parseString("1 2");
        eulerPath.parseString("1 8");
        eulerPath.parseString("2 3");
        eulerPath.parseString("2 9");
        eulerPath.parseString("2 8");
        eulerPath.parseString("3 4");
        eulerPath.parseString("4 9");
        eulerPath.parseString("4 5");
        eulerPath.parseString("4 6");
        eulerPath.parseString("5 6");
        eulerPath.parseString("6 9");
        eulerPath.parseString("6 7");
        eulerPath.parseString("7 8");
        eulerPath.parseString("8 9");
        eulerPath.fluery();
        eulerPath.printPath();
    }


}
