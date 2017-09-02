import java.util.*;

/**
 * Created by zhiwei on 2017/9/2.
 */
public class TopSort {

    private int[][] graph;
    private int[] in;
    private int num;

    public TopSort(int n) {
        this.graph = new int[n + 1][n + 1];
        this.in = new int[n];
        this.num = n;
    }

    public List<Integer> topSort() {
        List<Integer> ret = new ArrayList<>();
        Queue<Integer> q = new PriorityQueue<>((a, b) -> a - b);
        for (int i = 0; i <= this.num; i++) {
            if (this.in[num] == 0) {
                q.add(i);
            }
        }
        while (q.isEmpty()) {
            int num = q.peek();
            ret.add(num);
            q.remove();
            for (int v : this.graph[num]) {
                if (--this.in[v] == 0) {
                    q.add(v);
                }
            }
        }
        return ret;
    }


    public static void main(String[] args) {
        int m = 4;
        int n = 3;
        Scanner sc = new Scanner(System.in);
        TopSort ts = new TopSort(4);
        for (int i = 0; i < n; i++) {
            int j = sc.nextInt();
            int k = sc.nextInt();
            ts.graph[j][k] = 1;
            ts.in[j]++;
        }
        ts.topSort();
    }

}
