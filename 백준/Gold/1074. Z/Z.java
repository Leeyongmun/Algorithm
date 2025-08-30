import java.util.Scanner;

public class Main {
    static int k, n, m;
    static int ret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        k = sc.nextInt();
        n = sc.nextInt();
        m = sc.nextInt();
        solve(0, 0, 1 << k);
        System.out.println(ret);
    }

    private static void solve (int y, int x, int size){
        if(size == 1){
            return;
        }
        int half = size >> 1;
        int cnt = half * half;
        if(n < y + half && m < x + half){
            solve(y, x, half);
        }
        else if(n < y + half && m >= x + half){
            ret += cnt;
            solve(y, x + half, half);
        }
        else if(n >= y + half && m < x + half){
            ret += 2 * cnt;
            solve(y + half, x, half);
        }
        else{
            ret += 3 * cnt;
            solve(y + half, x + half, half);
        }
    }
}
