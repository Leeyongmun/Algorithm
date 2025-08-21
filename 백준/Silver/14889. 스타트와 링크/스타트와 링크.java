import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static int[][] a;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new int[n][n];
        for(int i = 0; i < n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < n; j++){
                a[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int ret = 987654321;
        for(int mask = (1 << (n / 2)) - 1; mask <= (1 << n) - (1 << (n/2)); mask++){
            if((mask & 1) == 0) continue; // 0번 비트는 1인것만 탐색 -> 여집합의 결과와 동일하기 때문에 시간을 절반 줄일 수 있음
            if(Integer.bitCount(mask) != n / 2) continue;
            int sum_a = sumScore(mask);
            int sum_b = sumScore((~mask) & ((1 << n) - 1));
            ret = Math.min(Math.abs(sum_a - sum_b), ret);
        }
        System.out.println(ret);
    }
    
    private static int sumScore(int mask){
        int sum = 0;
        for(int i = 0; i < n; i++){
            if((mask & (1 << i)) != 0){
                for(int j = i + 1; j < n; j++){
                    if((mask & (1 << j)) != 0 && j != i){
                        sum += a[i][j] + a[j][i];    
                    }
                }
            }
        }
        return sum;
    }
}