import java.util.Scanner;

public class Main {
    static int n;
    static char[][] a;
    static StringBuilder ret = new StringBuilder("");

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new char[n][n];
        for(int i = 0; i < n; i++){
            String s = sc.next();
            for(int j = 0; j < n; j++){
                a[i][j] = s.charAt(j);
            }
        }
        solve(0, 0, n);
        System.out.println(ret);
    }

    private static void solve(int y, int x, int size){
        if(size == 1){
            ret.append(a[y][x]);
            return;
        }
        int sum = 0;
        for(int i = y; i < y + size; i++){
            for(int j = x; j < x + size; j++){
                sum += a[i][j] - '0';
            }
        }
        if(sum == size * size){
            ret.append("1");
        }else if(sum == 0){
            ret.append("0");
        }else{
            ret.append("(");
            solve(y, x, size / 2);
            solve(y, x + size / 2, size / 2);
            solve(y + size / 2, x, size / 2);
            solve(y + size / 2, x + size / 2, size / 2);
            ret.append(")");
        }
    }
}
