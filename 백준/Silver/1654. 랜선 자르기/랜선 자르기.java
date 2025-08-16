import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int n, k;
    static int[] a;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        a = new int[n];
        long right = 0;
        long left = 1;
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
            right = Math.max(right, a[i]);
        }
        long max = 0;
        while(left <= right){
            long mid = (left + right) / 2;
            int cnt = 0;
            for(int i = 0; i < n; i++){
                cnt += a[i] / mid;
            }
            if(cnt >= k){
                left = mid + 1;
                max = Math.max(max, mid);
            }else{
                right = mid - 1;
            }
        }
        System.out.println(max);
    }
}
