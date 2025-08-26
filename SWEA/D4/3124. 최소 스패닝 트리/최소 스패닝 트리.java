import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    static int T, n, m;
    static Edge[] e;
    static int[] parent;
    static long ret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            m = sc.nextInt();
            parent = new int[n + 1];
            e = new Edge[m];
            int cnt = 0;
            ret = 0;
            for(int i = 1; i <= n; i++){
                parent[i] = i;
            }
            for(int i = 0; i < m; i++){
                int from = sc.nextInt();
                int to = sc.nextInt();
                int w = sc.nextInt();
                e[i] = new Edge(from, to, w);
            }
            Arrays.sort(e);
            for(Edge cur : e){
                if(find(cur.from) == find(cur.to)) continue;
                merge(cur.from, cur.to);
                ret += cur.w;
                cnt++;
                if(cnt == n - 1) break;
            }
            System.out.println("#" + t + " " + ret);
        }
    }

    private static int find(int x){
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    private static void merge(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        parent[x] = y;
    }
}

class Edge implements Comparable<Edge>{
    int from, to, w;

    Edge(int from, int to, int w){
        super();
        this.from = from;
        this.to = to;
        this.w = w;
    }

    @Override
    public int compareTo(Edge o) {
        // TODO Auto-generated method stub
        return Integer.compare(this.w, o.w);
    }
    
}
