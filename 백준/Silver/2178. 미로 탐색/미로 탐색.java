import java.util.*;

public class Main {
	static int[] dy = {-1, 0, 1, 0};
	static int[] dx = {0, 1, 0, -1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		sc.nextLine();
		String[] s = new String[n];
		int[][] a = new int[n][m];
		
		for(int i = 0; i < n; i++) {
			s[i] = sc.nextLine();
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				a[i][j] = s[i].charAt(j) - '0';
			}
		}
		int[][] visited = new int[n][m];
		visited[0][0] = 1;
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {0,0});
		while(!q.isEmpty()) {
			int[] pos = q.poll();
			int y = pos[0];
			int x = pos[1];
			for(int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if(visited[ny][nx] != 0 || a[ny][nx] == 0) continue;
				q.offer(new int[] {ny,nx});
				visited[ny][nx] = visited[y][x] + 1;
			}
		}
		System.out.println(visited[n - 1][m - 1]);
	}
}