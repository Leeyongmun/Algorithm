import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
    static int len;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int t = 1; t <= 10; t++){
            len = sc.nextInt();
            int start = sc.nextInt();
            ArrayList<Integer>[] a = new ArrayList[101]; 
            boolean[] visited = new boolean[101];
            for(int i = 1; i <= 100; i++){
                a[i] = new ArrayList<>();
            }
            for(int i = 0; i < len/2; i++){
                int from = sc.nextInt();
                int to = sc.nextInt();
                a[from].add(to);
            }
            int ret = 0;
            Queue<Integer> q = new ArrayDeque<>();
            q.offer(start);
            visited[start] = true;
            while(!q.isEmpty()){
                int size = q.size();
                int max = 0;
                for(int i = 0; i < size; i++){
                    int cur = q.poll();
                    max = Math.max(max, cur);
                    for(int next : a[cur]){
                        if(visited[next]) continue;
                        q.offer(next);
                        visited[next] = true;
                    }
                }
                if(q.isEmpty()){
                    ret = max;
                }
            }
            System.out.println("#" + t + " " + ret);
        }
    }
}
