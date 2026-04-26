import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int n, l, r, x;
    static int[] a;
    static int ret = 0;

    static class Info{
        int sum, min, max;
        Info(int sum, int min, int max){
            this.sum = sum;
            this.min = min;
            this.max = max;
        }
    }

    static Info cal_score(int mask){
        Info info = new Info(0, 987654321, -1);
        for(int i = 0; i < n; i++){
            if((mask & (1 << i)) != 0){
                info.sum += a[i];
                info.min = Math.min(info.min, a[i]);
                info.max = Math.max(info.max, a[i]);
            }
        }
        return info;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        l = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        
        a = new int[n];
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 1; i < (1 << n); i++){
            Info info = cal_score(i);
            int diff = info.max - info.min;
            if(info.sum >= l && info.sum <= r && diff >= x) ret++;
        }

        System.out.println(ret);
    }
}
