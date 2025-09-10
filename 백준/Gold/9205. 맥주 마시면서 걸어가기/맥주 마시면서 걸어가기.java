import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int T, n;
    static int[][] dist;
    static Pair[] p;

    // 플루이드 워셜 풀이
    // public static void main(String[] args) {
    //     Scanner sc = new Scanner(System.in);
    //     T = sc.nextInt();
    //     for(int t = 1; t <= T; t++){
    //         n = sc.nextInt();
    //         p = new Pair[n + 2];
    //         for(int i = 0; i < n + 2; i++){
    //             int x = sc.nextInt();
    //             int y = sc.nextInt();
    //             p[i] = new Pair(x, y);
    //         }
    //         dist = new int[n + 2][n + 2];
    //         for(int i = 0; i < n + 2; i++){
    //             for(int j = 0; j < n + 2; j++){
    //                 if(i == j) dist[i][j] = 0;
    //                 else dist[i][j] = 987654321;
    //             }
    //         }
    //         for(int i = 0; i < n + 2; i++){
    //             for(int j = 0; j < n + 2; j++){
    //                 if(i == j) continue;
    //                 int d = Math.abs(p[i].y - p[j].y) + Math.abs(p[i].x - p[j].x);
    //                 dist[i][j] = d <= 1000 ? 1 : 987654321;
    //             }
    //         }
    //         for(int k = 0; k < n + 2; k++){
    //             for(int i = 0; i < n + 2; i++){
    //                 if(dist[i][k] == 987654321) continue;
    //                 for(int j = 0; j < n + 2; j++){
    //                     if(dist[k][j] == 987654321) continue;
    //                     dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
    //                 }
    //             }
    //         }
    //         System.out.println(dist[0][n + 1] != 987654321 ? "happy" : "sad");
    //     }
    // }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            p = new Pair[n + 2];
            ArrayList<Integer>[] graph = new ArrayList[n + 2];
            for(int i = 0; i < n + 2; i++){
                graph[i] = new ArrayList<>();
            }
            for(int i = 0; i < n + 2; i++){
                int x = sc.nextInt();
                int y = sc.nextInt();
                p[i] = new Pair(x, y);
            }
            for(int i = 0; i < n + 2; i++){
                for(int j = 0; j < n + 2; j++){
                    if(i == j) continue;
                    int d = Math.abs(p[i].y - p[j].y) + Math.abs(p[i].x - p[j].x);
                    if(d <= 1000){
                        graph[i].add(j);
                        graph[j].add(i);
                    }
                }
            }
            boolean[] visited = new boolean[n + 2];
            Queue<Integer> q = new ArrayDeque<>();
            q.offer(0);
            visited[0] = true;
            while(!q.isEmpty()){
                int cur = q.poll();
                for(int next : graph[cur]){
                    if(visited[next]) continue;
                    q.offer(next);
                    visited[next] = true;
                }
            }
            System.out.println(visited[n + 1] ? "happy" : "sad");
        }
    }

    static class Pair{
        int x, y;
        Pair(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}
