import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Solution {

    static class Edge{
        int from, to;
        long w;
        Edge(int from, int to, long w){
            this.from = from;
            this.to = to;
            this.w = w;
        }
    }

    static int T, n;
    static int[] parent;
    static ArrayList<Edge> edge;
    static int[] y;
    static int[] x;
    static double tax;
    static long ret;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            edge = new ArrayList<>();
            parent = new int[n];
            ret = 0;
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
            y = new int[n];
            x = new int[n];
            for(int i = 0; i < n; i++){
                x[i] = sc.nextInt();
            }
            for(int i = 0; i < n; i++){
                y[i] = sc.nextInt();
            }
            tax = sc.nextDouble();
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    long dx = x[i] - x[j];
                    long dy = y[i] - y[j];
                    long dist = dx * dx + dy * dy;
                    edge.add(new Edge(i, j, dist));
                }
            }
            edge.sort(Comparator.comparingLong(a -> a.w));

            int cnt = 0;
            long sum = 0;
            for(Edge e : edge){
                if(!merge(e.from, e.to)) continue;
                sum += e.w;
                cnt++;
                if(cnt == n - 1) break;
            }
            System.out.println("#" + t + " " + Math.round(sum * tax));
        }
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
}

