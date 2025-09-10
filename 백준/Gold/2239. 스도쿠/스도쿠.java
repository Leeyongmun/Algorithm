import java.util.Scanner;

public class Main {
    static int[][] a = new int[10][10];
    static boolean[][] check1 = new boolean[10][10];
    static boolean[][] check2 = new boolean[10][10];
    static boolean[][] check3 = new boolean[10][10];
    static boolean flag = false;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 9; i++){
            String s = sc.next();
            for(int j = 0; j < 9; j++){
                a[i][j] = s.charAt(j) - '0';
                if(a[i][j] != 0){
                    check1[i][a[i][j]] = true;
                    check2[j][a[i][j]] = true;
                    check3[(i / 3) * 3 + j / 3][a[i][j]] = true;
                }
            }
        }
        solve(0);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                System.out.print(a[i][j]);
            }
            System.out.println();
        }
    }
    
    private static void solve(int idx){
        if(idx == 81){
            flag = true;
            return;
        }
        if(flag) return;
        int y = idx / 9;
        int x = idx % 9;
        if(a[y][x] != 0){
            solve(idx + 1);
            return;
        }
        for(int i = 1; i <= 9; i++){
            if(check1[y][i] || check2[x][i] || check3[(y / 3) * 3 + x / 3][i]) continue;
            a[y][x] = i;
            check1[y][i] = true;
            check2[x][i] = true;
            check3[(y / 3) * 3 + x / 3][i] = true;
            solve(idx + 1);
            if(flag) return;
            a[y][x] = 0;
            check1[y][i] = false;
            check2[x][i] = false;
            check3[(y / 3) * 3 + x / 3][i] = false;
        }
    }
}
