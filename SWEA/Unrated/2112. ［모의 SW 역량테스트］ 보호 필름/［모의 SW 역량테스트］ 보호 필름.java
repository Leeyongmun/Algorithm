import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    static int T, d, w, k;
    static int[][] a, tmp;
    static int ret = 987654321;
    static int size;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            d = sc.nextInt();
            w = sc.nextInt();
            k = sc.nextInt();
            a = new int[d][w];
            ret = 987654321;
            for(int i = 0; i < d; i++){
                for(int j = 0; j < w; j++){
                    a[i][j] = sc.nextInt();
                }
            }
            tmp = new int[d][w];
            for(int mask = 0; mask < (1 << d); mask++){
                size = Integer.bitCount(mask);
                if(size >= ret) continue;
                for(int i = 0; i < d; i++){
                    tmp[i] = a[i].clone();
                }
                solve(mask, 0, 0, tmp);
            }
            System.out.println("#" + t + " " + ret);
        }
    }

    private static void solve(int mask, int now, int cnt, int[][] tmp){
        if(cnt == size){
            if(check()) ret = Math.min(size, ret);
            return;
        }
        for(int i = now; i < d; i++){
            if((mask & (1 << i)) != 0){
                Arrays.fill(tmp[i], 0);
                solve(mask, i + 1, cnt + 1, tmp);
                Arrays.fill(tmp[i], 1);
                solve(mask, i + 1, cnt + 1, tmp);
            }
        }
    }

    private static boolean check(){
        for(int j = 0; j < w; j++){
            int prev = tmp[0][j];
            int cnt = 1;
            boolean flag = false;
            for(int i = 1; i < d; i++){
                if(prev != tmp[i][j]){
                    cnt = 1;
                }
                else cnt++;
                if(cnt == k) flag = true;
                prev = tmp[i][j];
            }
            if(!flag) return false;
        }
        return true;
    }
}
