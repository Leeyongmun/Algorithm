import java.util.Scanner;

public class Solution {
    static int T, n, k;
    static int[][] a;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            k = sc.nextInt();
            a = new int[n][n];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    a[i][j] = sc.nextInt();
                }
            }
            int ret = check();
            System.out.println("#" + t + " " + ret);
        }
    }

    private static int check(){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(checkRow(i)){
                sum++;
            }
        }
        for(int i = 0; i < n; i++){
            if(checkCol(i)){
                sum++;
            }
        }
        return sum;
    }

    private static boolean checkRow(int x){
        int prev = a[0][x];
        int cnt = 1;
        boolean flag = false;
        for(int i = 1; i < n; i++){
            cnt++;
            if(prev == a[i][x]){
                if(flag){
                    if(cnt == k){
                        cnt = 0;
                        flag = false;
                    }
                }
            }
            if((prev != a[i][x]) && flag){
                return false;
            }
            if(Math.abs(prev - a[i][x]) > 1) return false;
            if(prev < a[i][x]){
                if(cnt - 1 < k){
                    return false;
                }
                cnt = 1;
            }
            if(prev > a[i][x]){
                flag = true;
                cnt = 1;
            }
            prev = a[i][x];
        }
        if(flag) {
            return false;
        }
        return true;
    }

    private static boolean checkCol(int y){
        int prev = a[y][0];
        int cnt = 1;
        boolean flag = false;
        for(int i = 1; i < n; i++){
            cnt++;
            if(prev == a[y][i]){
                if(flag){
                    if(cnt == k){
                        cnt = 0;
                        flag = false;
                    }
                }
            }
            if((prev != a[y][i]) && flag){
                return false;
            }
            if(Math.abs(prev - a[y][i]) > 1) return false;
            if(prev < a[y][i]){
                if(cnt - 1 < k){
                    return false;
                }
                cnt = 1;
            }
            if(prev > a[y][i]){
                flag = true;
                cnt = 1;
            }
            prev = a[y][i];
        }
        if(flag) return false;
        return true;
    }
}
