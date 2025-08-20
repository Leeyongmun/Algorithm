import java.util.*;
import java.io.*;

public class Main {
	static int n, k;
	static boolean[] visited = new boolean[100001];
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
	
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		Queue<Integer> q = new LinkedList<>();
		visited[n] = true;
		q.offer(n);
		int t = 0;
		while(!q.isEmpty()) {
			int sz = q.size();
			for(int i = 0; i < sz; i++) {
				int now = q.poll();
				if (now == k) {
					System.out.println(t);
					return;
				}
				if(now + 1 <= 100000 && !visited[now + 1]) {
					q.offer(now + 1);
					visited[now + 1] = true;
				}
				if(now - 1 >= 0 && !visited[now - 1]) {
					q.offer(now - 1);
					visited[now - 1] = true;
				}
				if(now * 2 <= 100000 && !visited[2 * now]) {
					q.offer(now * 2);
					visited[now * 2] = true;
				}
			}
			t++;
		}
	}
}