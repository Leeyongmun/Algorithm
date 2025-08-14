import java.util.Scanner;

public class Main {
    static int n;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        int t = n / 5;
        int ret = -1;
        for(int i = t; i >= 0; i--){
            int cnt = i;
            int tmp = n - (i * 5);
            if(tmp % 3 != 0) continue;
            else{
                cnt += tmp / 3;
                ret = cnt;
                break;
            }
        }
        System.out.println(ret);
    }
}
