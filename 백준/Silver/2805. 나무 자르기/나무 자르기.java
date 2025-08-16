import java.util.Scanner;

public class Main {
    static int n, k;
    static int[] a;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        a = new int[n];
        int r = -1;
        int l = 0;
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
            r = Math.max(r, a[i]);
        }
        while(l <= r){
            int m = (l + r) / 2;
            long cnt = 0;
            for(int i = 0; i < n; i++){
                if(a[i] > m) cnt += (long)a[i] - m;
                if(cnt >= k) break;
            }
            if(cnt >= k) l = m + 1;
            else r = m - 1;
        }
        System.out.println(l - 1);
    }
}
