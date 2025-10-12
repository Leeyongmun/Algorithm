import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[][] a;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        a = new int[n][m];
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < m; j++){
                a[i][j] = Integer.parseInt(st.nextToken()); 
            }
        }
        int t = 0;
        while(true){
            t++;
            melt();
            int cnt = check();
            if(cnt == 0){
                t = 0;
                break;
            }
            else if(cnt >= 2){
                break;
            }
        }
        System.out.println(t);
    }

    private static void melt(){
        int[][] tmp = new int[n][m];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] != 0){
                    int cnt = 0;
                    for(int d = 0; d < 4; d++){
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if(a[ny][nx] == 0) cnt++;
                    }
                    tmp[i][j] = (a[i][j] - cnt) < 0 ? 0 : a[i][j] - cnt; 
                }
            }
        }
        a = tmp;
    }

    private static int check(){
        visited = new boolean[n][m];
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] != 0 && !visited[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    private static void dfs(int y, int x){
        visited[y][x] = true;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(a[ny][nx] != 0 && !visited[ny][nx]) dfs(ny, nx);
        }
    }
}
