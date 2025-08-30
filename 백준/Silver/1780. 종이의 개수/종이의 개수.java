import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a;
    static int plus = 0, zero = 0, minus = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new int[n][n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = sc.nextInt();
            }
        }

        solve(0, 0, n);
        System.out.println(minus);
        System.out.println(zero);
        System.out.println(plus);
    }

    private static void solve(int y, int x ,int size){
        int prev = a[y][x];
        for(int i = y; i < y + size; i++){
            for(int j = x; j < x + size; j++){
                if(prev != a[i][j]){
                    int nSize = size / 3;
                    solve(y, x, nSize);
                    solve(y, x + nSize, nSize);
                    solve(y, x + 2 * nSize, nSize);
                    solve(y + nSize, x, nSize);
                    solve(y + nSize, x + nSize, nSize);
                    solve(y + nSize, x + 2 * nSize, nSize);
                    solve(y + 2 * nSize, x, nSize);
                    solve(y + 2 * nSize, x + nSize, nSize);
                    solve(y + 2 * nSize, x + 2 * nSize, nSize);
                    return;
                }
            }
        }
        if(prev == -1){
            minus++;
        }
        if(prev == 0){
            zero++;
        }
        if(prev == 1){
            plus++;
        }
    }
}
