import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static int n, m;
    static int[] a, b;
    static StringBuilder ret = new StringBuilder();
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        a = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(a);
        m = Integer.parseInt(br.readLine());
        b = new int[m];
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < m; i++){
            b[i] = Integer.parseInt(st.nextToken());
            int k = getUpperBound(b[i]) - getLowerBound(b[i]);
            ret.append(k).append(" ");
        }
        System.out.println(ret);
    }

    private static int getLowerBound(int num){
        int l = 0;
        int r = n - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(num > a[m]) l = m + 1;
            else r = m - 1;
        }
        return l;
    }

    private static int getUpperBound(int num){
        int l = 0;
        int r = n - 1;
        while(l <= r){
            int m = (l + r) / 2;
            if(num >= a[m]) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
}
