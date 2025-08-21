import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int n, m;
    static ArrayList<Integer>[] a;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new ArrayList[n + 1];
        int[] ind = new int[n + 1];
        for(int i = 1; i <= n; i++){
            a[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; i++){
            int c = sc.nextInt();
            int from = sc.nextInt();
            for(int j = 0; j < c- 1; j++){
                int to = sc.nextInt();
                a[from].add(to);
                ind[to]++;
                from = to;
            }
        }
        Queue<Integer> q = new ArrayDeque<>();
        for(int i = 1; i <= n; i++){
            if(ind[i] == 0) q.offer(i); 
        }

        if(q.isEmpty()){
            System.out.println(0);
            return;
        }
        
        ArrayList<Integer> tmp = new ArrayList<>();
        while(!q.isEmpty()){
            int cur = q.poll();
            for(int next : a[cur]){
                ind[next]--;
                if(ind[next] == 0) q.offer(next);
            }
            tmp.add(cur);
        }
        if(tmp.size() == n){
            for(int num : tmp){
                System.out.println(num);
            }
        }
        else{
            System.out.println(0);
        }
    }
}
