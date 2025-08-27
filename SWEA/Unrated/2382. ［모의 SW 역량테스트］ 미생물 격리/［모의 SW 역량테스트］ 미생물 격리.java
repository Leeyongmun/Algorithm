import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    static int T, n, m, k;
    static int[] cnt;
    static Data[] a;
    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, -1, 1};
    static int[][] sumCount;     
    static int[][] maxCount;     
    static int[][] dirMax; 
    static int[][] idx;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            m = sc.nextInt();
            k = sc.nextInt();
            cnt = new int[k];
            a = new Data[k];
            for(int i = 0; i < k; i++){
                int y = sc.nextInt();
                int x = sc.nextInt();
                cnt[i] = sc.nextInt();
                int dir = sc.nextInt();
                a[i] = new Data(y, x, dir - 1);
            }
            sumCount = new int[n][n];
            maxCount = new int[n][n];
            dirMax = new int[n][n];
            idx = new int[n][n];
            while(m-- != 0){
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        sumCount[i][j] = 0;
                        maxCount[i][j] = 0;
                        dirMax[i][j]   = 0;   // 방향은 어차피 아래에서 갱신됨
                        idx[i][j]      = -1;  // 대표 인덱스 초기화(안전하게 -1)
                    }
                }
                for(int i = 0; i < k; i++){
                    if(cnt[i] == 0) continue;
                    int y = a[i].y;
                    int x = a[i].x;
                    int dir = a[i].dir;
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if(check(ny, nx)){
                        cnt[i] /= 2;
                        if(dir == 0){
                            a[i].dir = 1;
                        }
                        else if(dir == 1){
                            a[i].dir = 0;
                        }
                        else if(dir == 2){
                            a[i].dir = 3;
                        }
                        else if(dir == 3){
                            a[i].dir = 2;
                        }
                    }
                    a[i].y = ny;
                    a[i].x = nx;

                    if(cnt[i] == 0) continue;
                    sumCount[ny][nx] += cnt[i];
                    if(cnt[i] > maxCount[ny][nx]){
                        maxCount[ny][nx] = cnt[i];
                        dirMax[ny][nx] = a[i].dir;
                        idx[ny][nx] = i;
                    }
                }
                
                for(int i = 0; i < k; i++){
                    if(cnt[i] == 0) continue;
                    int y = a[i].y;
                    int x = a[i].x;
                    if(idx[y][x] == i){
                        cnt[i] = sumCount[y][x];
                        a[i].dir = dirMax[y][x];
                    }else{
                        cnt[i] = 0;
                    }
                }
            }
            int ret = 0;
            for(int i = 0; i < k; i++){
                ret += cnt[i];
            }
            System.out.println("#" + t + " " + ret);
        }    
    }

    private static boolean check(int y, int x){
        if(y == 0 || y == n - 1 || x == 0 || x == n - 1){
            return true;
        }
        return false;
    }

    static class Data{
        int y, x, dir;
        Data(int y, int x, int dir){
            this.y = y;
            this.x = x;
            this.dir = dir;
        }
    }
}
