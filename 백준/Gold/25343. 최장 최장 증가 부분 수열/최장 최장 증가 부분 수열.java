import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a;
    static int ret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = sc.nextInt();
            }
        }
        int[][] dp = new int[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = 1;
                for(int y = 0; y <= i; y++){
                    for(int x = 0; x <= j; x++){
                        if(a[y][x] < a[i][j]){
                            dp[i][j] = Math.max(dp[i][j], dp[y][x] + 1);
                        }
                    }
                }
                ret = Math.max(ret, dp[i][j]);
            }
        }
        System.out.println(ret);
    }
}
