import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, k;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        if(n == k){
            System.out.println(0);
            System.out.println(1);
            return;
        }
        Queue<Integer> q = new ArrayDeque<>();
        boolean[] visited = new boolean[100001];
        boolean[] willVisit = new boolean[100001];
        
        q.offer(n);
        visited[n] = true;
        int t = 0;
        int w = 0;
        boolean flag = false;
        while(!q.isEmpty() && !flag){
            int size = q.size();
            t++;
            ArrayList<Integer> tmp = new ArrayList<>();
            for(int i = 0; i < size; i++){
                int cur = q.poll();
                int[] nexts = {cur - 1, cur + 1, cur * 2};
                for(int next : nexts){
                    if(next < 0 || next > 100000) continue;

                    if(next == k){
                        flag = true;
                        w++;
                        continue;
                    }
                    if(!visited[next]){
                        tmp.add(next);
                        q.offer(next);
                    }
                }
            }
            for(int x : tmp){
                visited[x] = true;
            }
        }
        System.out.println(t);
        System.out.println(w);
    }
}
