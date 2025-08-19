import java.util.Scanner;

public class Main {
    static int n;
    static int[][] a = new int[100][100];
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int i = 0; i < n; i++){
            int x = sc.nextInt();
            int y = sc.nextInt();
            for(int j = y; j < y + 10; j++){
                for(int l = x; l < x + 10; l++){
                    a[j][l] = 1;
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < 100; i++){
            for(int j = 0; j < 100; j++){
                if(a[i][j] == 1){
                    for(int dir = 0; dir < 4; dir++){
                        int ny = i + dy[dir];
                        int nx = j + dx[dir];
                        if(ny < 0 || nx < 0 || ny >= 100 || nx >= 100 || a[ny][nx] == 0){
                            ret++;
                        }
                    }
                }
            }
        }
        System.out.println(ret);
    }
}
