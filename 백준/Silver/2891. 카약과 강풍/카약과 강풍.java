import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    static int n, s, r;
    static boolean[] flag = new boolean[11];
    static HashSet set = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        s = Integer.parseInt(st.nextToken());
        r = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < s; i++){
            int idx = Integer.parseInt(st.nextToken());
            set.add(idx);
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < r; i++){
            int idx = Integer.parseInt(st.nextToken());
            flag[idx] = true;
        }

        int ret = 0;

        for(int i = 1; i <= n; i++){
            if(set.contains(i) && flag[i]){
                flag[i] = false;
                set.remove(i);
            }
        }

        for(int i = 1; i <= n; i++){
            if(set.contains(i)){
                if(i - 1 > 0 && flag[i - 1]){
                    flag[i - 1] = false;
                    continue;
                }
                if(i + 1 <= n && flag[i + 1]){
                    flag[i + 1] = false;
                    continue;
                }
                ret++;
            }
        }
        System.out.println(ret);
    }
}
