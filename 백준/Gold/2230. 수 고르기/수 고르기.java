import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n, m;
    static int[] a;
    static int ret = 2000000001;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        int l = 0;
        int r = 0;
        while(r < n && l < n){
            if(a[r] - a[l] >= m){
                ret = Math.min(ret, a[r] - a[l]);
                l++;
            }
            else{
                r++;
            }
        }
        System.out.println(ret);
    }
}
