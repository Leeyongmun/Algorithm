import java.io.*;
import java.util.*;

public class Main {
    static class Pair {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static int n;
    static int[] tree;
    static StringBuilder ret = new StringBuilder();

    static void update(int idx) {
        while (idx <= n) {
            tree[idx] += 1;
            idx += (idx & -idx);
        }
    }

    static int sum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        Pair[] a = new Pair[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Pair(i + 1, Integer.parseInt(br.readLine()));
        }
        Arrays.sort(a, (x, y) -> {
            return x.second - y.second;
        });
        for (int i = 0; i < n; i++) {
            a[i] = new Pair(a[i].first, i + 1);
        }
        Arrays.sort(a, (x, y) -> {
            return x.first - y.first;
        });

        tree = new int[n + 1];
        for (int i = 0; i < n; i++) {
            int rank = a[i].second;
            int faster = i - sum(rank);
            ret.append(faster + 1).append('\n');
            update(rank);
        }

        System.out.println(ret);
    }
}
