import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a;  
    static boolean[][] visited; 
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    static ArrayList<Integer> tmp = new ArrayList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n][n];
        visited = new boolean[n][n];
        for(int i = 0; i < n; i++){
            String s = sc.next();
            for(int j = 0; j < n; j++){
                a[i][j] = s.charAt(j) - '0';
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == 1 && !visited[i][j]){
                    cnt++;
                    tmp.add(dfs(i, j));
                }
            }
        }
        System.out.println(cnt);
        Collections.sort(tmp);
        for(int sum : tmp){
            System.out.println(sum);
        }
    }

    private static int dfs(int y, int x){
        visited[y][x] = true;
        int sum = 1;
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if(a[ny][nx] == 0 || visited[ny][nx]) continue;
            sum += dfs(ny,nx);
        }
        return sum;
    }
}
