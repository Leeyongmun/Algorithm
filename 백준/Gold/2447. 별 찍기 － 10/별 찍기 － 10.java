import java.util.Scanner;

public class Main {
    static int n;
    static char[][] a;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        a = new char[n][n];
        printStar(0, 0, n, false);
        StringBuilder ret = new StringBuilder();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ret.append(a[i][j]);
            }
            ret.append('\n');
        }
        System.out.println(ret);
    }

    private static void printStar(int y, int x, int size, boolean flag){
        if(flag){
            for(int i = y; i < y + size; i++){
                for(int j = x; j < x + size; j++){
                    a[i][j] = ' ';
                }
            }
            return;
        }
        if(size == 1){
            a[y][x] = '*';
            return;
        }

        int nSize = size / 3;
        int cnt = 0;
        for(int i = y; i < y + size; i += nSize){
            for(int j = x; j < x + size; j += nSize){
                cnt++;
                if(cnt == 5){
                    printStar(i, j, nSize, true);
                }
                else{
                    printStar(i, j, nSize, false);
                }
            }
        }
    }
}
