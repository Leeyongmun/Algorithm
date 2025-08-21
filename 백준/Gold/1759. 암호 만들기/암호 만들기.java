import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n, m;
    static char[] a;
    static String ret;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new char[m];
        for(int i = 0; i < m; i++){
            a[i] = sc.next().charAt(0);
        }
        Arrays.sort(a);
        solve(0, 0, "");
    }

    private static void solve(int now, int cnt, String s){
        if(cnt == n){
            int cnt_moum = 0;
            for(int i = 0; i < s.length(); i++){
                if(check(s.charAt(i))) cnt_moum++;
            }
            if(cnt_moum >= 1 && s.length() - cnt_moum >= 2){
                System.out.println(s);
            }
            return;
        }
        for(int i = now; i < m; i++){
            solve(i + 1, cnt + 1, s + a[i]);
        }
    }

    private static boolean check(char c){
        return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
    }
}
