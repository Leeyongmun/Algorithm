import java.util.Scanner;

public class Solution {
    static int T, k;
    static int[][] a;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            k = sc.nextInt();
            a = new int[4][8];
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 8; j++){
                    a[i][j] = sc.nextInt();
                }
            }
            for(int i = 0; i < k; i++){
                int n = sc.nextInt() - 1;
                int dir = sc.nextInt();
                int mask = check();
                rotate(n, dir);
                int tmp_dir = dir;
                for(int j = n - 1; j >= 0; j--){
                    if((mask & (1 << j)) != 0){
                        tmp_dir = -tmp_dir;
                        rotate(j, tmp_dir);
                    }
                    else break;
                }
                tmp_dir = dir;
                for(int j = n + 1; j < 4; j++){
                    if((mask &(1 << (j - 1))) != 0){
                        tmp_dir = -tmp_dir;
                        rotate(j, tmp_dir);
                    }
                    else break;
                }
            }
            int ret = 0;
            for(int i = 0; i < 4; i++){
                if(a[i][0] == 1){
                    ret += (1 << i);
                }
            }
            System.out.println("#" + t + " " + ret);
        }
        
    }

    private static int check(){
        int mask = 0;
        for(int i = 0; i < 3; i++){
            if(a[i][2] != a[i + 1][6]){
                mask |= (1 << i);
            }
        }
        return mask;
    }

    private static void rotate(int n, int dir){
        if(dir == 1){
            int tmp = a[n][7];
            for(int i = 7; i > 0; i--){
                a[n][i] = a[n][i - 1];  
            }
            a[n][0] = tmp;
        }
        else{
            int tmp = a[n][0];
            for(int i = 0; i < 7; i++){
                a[n][i] = a[n][i + 1];
            }
            a[n][7] = tmp;
        }
    }
}
