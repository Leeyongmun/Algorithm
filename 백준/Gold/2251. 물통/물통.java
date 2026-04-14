import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    static int a, b, c;
    static boolean[][][] visited = new boolean[201][201][201];
    static int[] cap = new int[3];
    static TreeSet<Integer> water = new TreeSet<>();
    static Queue<int[]> q = new ArrayDeque<>();
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 3; i++) {
            cap[i] = Integer.parseInt(st.nextToken());
        }

        q.add(new int[]{0, 0, cap[2]});
        water.add(cap[2]);
        visited[0][0][cap[2]] = true;

        while (!q.isEmpty()) {
            int[] now = q.poll();
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == j) continue;
                    int[] next = now.clone();
                    int amount = Math.min(now[i], cap[j] - now[j]);
                    next[i] -= amount;
                    next[j] += amount;
                    if(visited[next[0]][next[1]][next[2]]) continue;
                    if(next[0] == 0) water.add(next[2]);
                    q.add(next);
                    visited[next[0]][next[1]][next[2]] = true;
                }
            }
        }

        for (int i : water) {
            sb.append(i).append(' ');
        }
        System.out.println(sb);
    }
}
