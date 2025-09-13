import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[][] dist;
    static int[][] next;
    static StringBuilder ret = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());
        dist = new int[n + 1][n + 1];
        next = new int[n + 1][n + 1];
        for(int i = 1; i <= n; i++){
            Arrays.fill(dist[i], 987654321);
            dist[i][i] = 0;
        }
        for(int i = 0; i < m; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());
            if(cost < dist[from][to]){
                dist[from][to] = cost;
                next[from][to] = to;
            }
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(dist[i][j] > dist[i][k] + dist[k][j]){
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                ret.append(dist[i][j] == 987654321 ? 0 : dist[i][j]).append(" ");
            }
            ret.append("\n");
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j || next[i][j] == 0) {
                    ret.append("0\n");
                    continue;
                }
                ArrayList<Integer> path = getPath(i, j);
                ret.append(path.size()).append(" ");
                for(int p : path){
                    ret.append(p).append(" ");
                }
                ret.append('\n');
            }
        }
        System.out.println(ret);
    }

    private static ArrayList<Integer> getPath(int i, int j){
        ArrayList<Integer> path = new ArrayList<>();
        path.add(i);
        while(i != j){
            i = next[i][j];
            path.add(i);
        }
        return path;
    }
}
