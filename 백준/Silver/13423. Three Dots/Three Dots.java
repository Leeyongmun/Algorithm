import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int T;
    static int n;
    static int[] a;
    static StringBuilder ret = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        T = Integer.parseInt(br.readLine());
        for(int t = 1; t <= T; t++){
            n = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            a = new int[n];
            for(int i = 0; i < n; i++){
                a[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(a);
            int cnt = 0;
            for(int i = 0; i < n; i++){
                for(int j = i + 1; j < n; j++){
                    if(Arrays.binarySearch(a, a[j] + a[j] - a[i]) >= 0) cnt++;
                }
            }
            ret.append(cnt).append('\n');
        }
        System.out.println(ret);
    }
}
