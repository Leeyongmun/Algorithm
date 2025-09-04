import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    static int n, k;
    static int[] dist;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        dist = new int[100001];
        Arrays.fill(dist, 987654321);
        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e.t));
        dist[n] = 0;
        pq.offer(new Pair(n, 0));
        while(!pq.isEmpty()){
            Pair now = pq.poll();
            int cur = now.now;
            int t = now.t;
            if(cur == k) break;
            if(dist[cur] < t) continue;
            if(cur * 2 <= 100000){
                int nt = t;
                if(dist[cur * 2] > nt){
                    dist[cur*2] = nt;
                    pq.offer(new Pair(cur * 2, nt));
                }
            }
            if(cur + 1 <= 100000){
                int nt = t + 1;
                if(dist[cur + 1] > nt){
                    dist[cur + 1] = nt;
                    pq.offer(new Pair(cur + 1, nt));
                }
            }
            if(cur - 1 >= 0){
                int nt = t + 1;
                if(dist[cur - 1] > nt){
                    dist[cur - 1] = nt;
                    pq.offer(new Pair(cur - 1, nt));
                }
            }
        }
        System.out.println(dist[k]);
    }

    static class Pair{
        int now, t;
        Pair(int now, int t){
            this.now = now;
            this.t = t;
        }
    }
}
