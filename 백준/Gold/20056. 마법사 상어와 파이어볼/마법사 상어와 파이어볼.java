import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int n, m, k;
    static int[] dy ={-1, -1, 0, 1, 1, 1, 0, -1};
    static int[] dx ={0, 1, 1, 1, 0, -1, -1, -1};

    static class Fireball{
        int y, x, m, d, s;
        Fireball(int y, int x, int m, int d, int s){
            this.y = y;
            this.x = x;
            this.m = m;
            this.d = d;
            this.s = s;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        ArrayList<Fireball> fireball = new ArrayList<>();
        for(int i = 0; i < m; i++){
            int y, x, m, d, s;
            st = new StringTokenizer(br.readLine());
            y = Integer.parseInt(st.nextToken());
            x = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            fireball.add(new Fireball(y, x, m, d, s)); // 각 파이어볼 정보 저장
        }

        while(k-- > 0){
            ArrayList<Integer>[][] map = new ArrayList[n + 1][n + 1];
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    map[i][j] = new ArrayList<>();
                }
            }
            for(int i = 0; i < fireball.size(); i++){
                Fireball cur = fireball.get(i);
                if(cur.m == 0) continue;
                int move = cur.s % n; 
                int ny = ((cur.y - 1 + dy[cur.d] * move) % n + n) % n + 1;
                int nx = ((cur.x - 1 + dx[cur.d] * move) % n + n) % n + 1;
                cur.y = ny;
                cur.x = nx;
                map[ny][nx].add(i);
            }
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(map[i][j].size() < 2) continue;
                    int sum_m = 0;
                    int sum_s = 0;
                    boolean isOdd = false;
                    boolean isEven = false;
                    for(int idx : map[i][j]){
                        Fireball tmp = fireball.get(idx);
                        sum_m += tmp.m;
                        sum_s += tmp.s;
                        if(tmp.d % 2 == 1) isOdd = true;
                        else isEven = true;
                        fireball.get(idx).m = 0;
                    }
                    int dir = (isOdd && isEven) ? 1 : 0;
                    sum_m /= 5;
                    if(sum_m == 0) continue;
                    sum_s /= map[i][j].size();
                    for(int l = 0; l < 4; l++){
                        fireball.add(new Fireball(i, j, sum_m, dir, sum_s));
                        dir += 2;
                    }
                }
            }
        }
        int ret = 0;
        for(Fireball fb : fireball){
            ret += fb.m;
        }
        System.out.println(ret);
    }
}
