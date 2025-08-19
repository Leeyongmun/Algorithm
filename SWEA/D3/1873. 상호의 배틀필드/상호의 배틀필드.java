import java.util.Scanner;

public class Solution {
    static int T, n, m;
    static char[][] a;
    static int dy[] = {-1, 0, 1, 0};
    static int dx[] = {0, 1, 0, -1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            m = sc.nextInt();
            a = new char[n][m];
            int dir = -1;
            Pair tank = new Pair(0, 0);
            for(int i = 0; i < n; i++){
                String s = sc.next();
                for(int j = 0; j < m; j++){
                    a[i][j] = s.charAt(j);  
                    if(a[i][j] == '^'){
                        tank.y = i;
                        tank.x = j;
                        dir = 0;
                    }
                    else if(a[i][j] == 'v'){
                        tank.y = i;
                        tank.x = j;
                        dir = 2;
                    }
                    else if(a[i][j] == '>'){
                        tank.y = i;
                        tank.x = j;
                        dir = 1;
                    }
                    else if(a[i][j] == '<'){
                        tank.y = i;
                        tank.x = j;
                        dir = 3;
                    }
                }
            }
            int len = sc.nextInt();
            String cmd_line = sc.next();
            for(int i = 0; i < len; i++){
                char cmd = cmd_line.charAt(i);
                if(cmd == 'U'){
                    dir = 0;
                    int ny = tank.y + dy[dir];
                    int nx = tank.x + dx[dir];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] != '.') continue;
                    a[tank.y][tank.x] = '.';
                    tank.y = ny;
                    tank.x = nx; 
                }else if(cmd == 'D'){
                    dir = 2;
                    int ny = tank.y + dy[dir];
                    int nx = tank.x + dx[dir];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] != '.') continue;
                    a[tank.y][tank.x] = '.';
                    tank.y = ny;
                    tank.x = nx; 
                }else if(cmd == 'L'){
                    dir = 3;
                    int ny = tank.y + dy[dir];
                    int nx = tank.x + dx[dir];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] != '.') continue;
                    a[tank.y][tank.x] = '.';
                    tank.y = ny;
                    tank.x = nx; 
                }else if(cmd == 'R'){
                    dir = 1;
                    int ny = tank.y + dy[dir];
                    int nx = tank.x + dx[dir];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] != '.') continue;
                    a[tank.y][tank.x] = '.';
                    tank.y = ny;
                    tank.x = nx; 
                } else if(cmd == 'S'){
                    int ny = tank.y;
                    int nx = tank.x;
                    while(true){
                        ny += dy[dir];
                        nx += dx[dir];
                        if(ny < 0 || nx < 0 || ny >= n || nx >= m) break;
                        if(a[ny][nx] == '#') break;
                        if(a[ny][nx] == '*'){
                            a[ny][nx] = '.';
                            break;
                        }
                    }
                }
            }
            if(dir == 0){
                a[tank.y][tank.x] = '^';
            }else if(dir == 1){
                a[tank.y][tank.x] = '>';
            }else if(dir == 2){
                a[tank.y][tank.x] = 'v';
            }else if(dir == 3){
                a[tank.y][tank.x] = '<';
            }
            System.out.print("#" + t + " ");
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    System.out.print(a[i][j]);
                }
                System.out.println();
            }
        }
    }
}

class Pair{
    int y;
    int x;
    Pair(int y, int x){
        this.y = y;
        this.x = x;
    }
}