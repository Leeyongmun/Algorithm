import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[] a;
    static StringBuilder ret = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(a);
        m = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < m; i++){
            int num = Integer.parseInt(st.nextToken());
            int l = 0;
            int r = n - 1;
            boolean flag = false;
            while(l <= r){
                int mid = (l + r) / 2;
                if(num == a[mid]){
                    flag = true;
                    break;
                }else if(num > a[mid]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            if(flag){
                ret.append(1).append('\n');
            }else{
                ret.append(0).append('\n');
            }
        }
        System.out.println(ret);
    }
}
