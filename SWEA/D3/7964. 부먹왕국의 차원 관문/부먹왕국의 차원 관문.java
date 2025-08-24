import java.util.Scanner;

public class Solution {
    static int T;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            int n = sc.nextInt();
            int d = sc.nextInt();
            int[] a = new int[n];
            int ret = 0;
            int cnt = 0;
            for(int i = 0; i < n; i++){
                a[i] = sc.nextInt();
            }
            if(a[0] == 0){
                ret++;
            }
            if(a[n-1] == 0){
                ret++;
            }
            for(int i = 1; i < n-1; i++){
                if(a[i] == 0){
                    cnt++;
                }
                else if(a[i] == 1){
                    cnt = 0;
                }
                if(cnt == d){
                    cnt = 0;
                    ret++;
                }
            }
            System.out.println("#" + t + " " + ret);
        }
    }
}
