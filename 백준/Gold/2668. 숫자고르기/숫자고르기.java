import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;

public class Main {
    static int n;
    static int[] a;
    static boolean[] visited, finished;
    static TreeSet<Integer> ret = new TreeSet<>();

    static void dfs(int cur){
        visited[cur] = true;
        int next = a[cur];

        if(!visited[next]){
            dfs(next);
        }
        else if(!finished[next]){
            int tmp = next;
            while(tmp != cur){
                ret.add(tmp);
                tmp = a[tmp];
            }
            ret.add(cur);
        }
        finished[cur] = true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = Integer.parseInt(br.readLine());
        a = new int[n + 1];
        visited = new boolean[n + 1];
        finished = new boolean[n + 1];

        for(int i = 1; i <= n; i++){
            a[i] = Integer.parseInt(br.readLine());
        }

        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        System.out.println(ret.size());
        for(int x : ret){
            System.out.println(x);
        }
    }    
}
