import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    static int n, m;
    static int[] parent;
    static Edge[] edge;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        parent = new int[n + 1];
        edge = new Edge[m];
        for(int i = 1; i <= n; i++){
            parent[i] = i;
        }
        for(int i = 0; i < m; i++){
            int from = sc.nextInt();
            int to = sc.nextInt();
            int cost = sc.nextInt();
            edge[i] = new Edge(from, to, cost);
        }
        Arrays.sort(edge, Comparator.comparingInt(e -> e.cost));

        int cnt = 0;
        int ret = 0;
        int max = -1;
        for(int i = 0; i < m; i++){
            int a = edge[i].from;
            int b = edge[i].to;
            int w = edge[i].cost;
            if(!merge(a, b)) continue;
            cnt++;
            ret += w;
            max = Math.max(max, w);
            if(cnt == n - 1) break;
        }
        System.out.println(ret - max);
    }

    private static int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    private static boolean merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return false;
        parent[x] = y;
        return true;
    }

    static class Edge{
        int from, to, cost;
        Edge(int from, int to, int cost){
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }
}
