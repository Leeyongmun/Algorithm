import java.util.Scanner;

public class Solution {
    static int T, n;
    static String s;
    static int ret = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            ret = 0;
            n = sc.nextInt();
            int l = n / 2;
            int r = n / 2;
            for(int i = 0; i < n; i++){
                if(i >= 1 && i <= n / 2){
                    l--;
                    r++;
                } 
                else if(i > n / 2 && i < n){
                    l++;
                    r--;
                }
                s = sc.next();
                for(int j = 0; j < n; j++){
                    if(j >= l && j <= r){
                        ret += s.charAt(j) - '0';
                    }
                }
            }
            System.out.println("#" + t + " " + ret); 
        }
    }
}
