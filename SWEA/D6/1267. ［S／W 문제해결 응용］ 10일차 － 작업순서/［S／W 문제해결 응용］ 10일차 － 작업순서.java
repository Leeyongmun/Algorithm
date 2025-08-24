import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
    static int T = 10;
    static StringBuilder ret = new StringBuilder();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int t = 1; t <= T; t++){
            int n = sc.nextInt();
            int m = sc.nextInt();
            ArrayList<Integer>[] a = new ArrayList[n + 1];
            for(int i = 1; i <= n; i++){
                a[i] = new ArrayList<>();
            }
            int[] ind = new int[n + 1];
            for(int i = 0; i < m; i++){
                int from = sc.nextInt();
                int to = sc.nextInt();
                a[from].add(to);
                ind[to]++;
            }
            Queue<Integer> q = new ArrayDeque<>();
            for(int i = 1; i <= n; i++){
                if(ind[i] == 0) q.offer(i);
            }
            ret.append("#").append(t).append(" ");
            while(!q.isEmpty()){
                int cur = q.poll();
                for(int next : a[cur]){
                    ind[next]--;
                    if(ind[next] == 0) q.offer(next);
                }
                ret.append(cur).append(" ");
            }
            ret.append('\n');
        }
        System.out.println(ret);
    }
}
