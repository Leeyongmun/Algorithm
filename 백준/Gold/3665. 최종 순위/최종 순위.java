import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static int T;
    static int n, m;
    static int[] ind;
    static ArrayList<Integer>[] graph;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++){
            n = Integer.parseInt(br.readLine());

            ind = new int[n + 1];
            graph = new ArrayList[n + 1];
            for(int i = 1; i <= n; i++){
                graph[i] = new ArrayList<>();
            }

            int[] last = new int[n + 1];
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i < n; i++){
                last[i] = Integer.parseInt(st.nextToken());
            }

            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    graph[last[i]].add(last[j]);
                    ind[last[j]]++;
                }
            }

            int m = Integer.parseInt(br.readLine());
            for(int i = 0; i < m; i++){
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                if(graph[a].contains(b)){
                    graph[a].remove(Integer.valueOf(b));
                    graph[b].add(a);
                    ind[b]--;
                    ind[a]++;
                }
                else{
                    graph[b].remove(Integer.valueOf(a));
                    graph[a].add(b);
                    ind[a]--;
                    ind[b]++;
                }
            }

            Queue<Integer> q = new ArrayDeque<>();
            for(int i = 1; i <= n; i++){
                if(ind[i] == 0) q.offer(i);
            }

            ArrayList<Integer> ret = new ArrayList<>();
            boolean isAmbiguous = false;
            boolean isImpossible = false;

            for(int i = 0; i < n; i++){
                if(q.isEmpty()){
                    isImpossible = true;
                    break;
                }
                if(q.size() > 1){
                    isAmbiguous = true;
                }

                int cur = q.poll();
                ret.add(cur);

                for(int next : graph[cur]){
                    ind[next]--;
                    if(ind[next] == 0){
                        q.offer(next);
                    }
                }
            }
            if(isImpossible){
                System.out.println("IMPOSSIBLE");
            }
            else if(isAmbiguous){
                System.out.println("?");
            }
            else{
                for(int x : ret){
                    System.out.print(x + " ");
                }
                System.out.println();
            }
        }
    }
}
