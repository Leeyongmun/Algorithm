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
    static Queue<State> q = new ArrayDeque<>();
    static StringBuilder sb = new StringBuilder();

    static class State{
        int a, b, c;
        private State(int a, int b, int c){
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    static void move(int[] cur, int from, int to){
        int[] next = cur.clone();

        int amount = Math.min(cur[from], cap[to] - cur[to]);
        next[from] -= amount;
        next[to] += amount;
        
        if(visited[next[0]][next[1]][next[2]]) return;
        q.add(new State(next[0], next[1], next[2]));
        if(next[0] == 0) water.add(next[2]);
        visited[next[0]][next[1]][next[2]] = true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i < 3; i++){
            cap[i] = Integer.parseInt(st.nextToken());
        }

        q.add(new State(0, 0, cap[2]));
        water.add(cap[2]);
        visited[0][0][cap[2]] = true;

        while(!q.isEmpty()){
            State cur = q.poll();
            int[] now = {cur.a, cur.b, cur.c};
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(i == j) continue;
                    move(now, i, j);
                }
            }
        }

        for(int i : water){
            sb.append(i).append(' ');
        }
        System.out.println(sb);
    }
}
