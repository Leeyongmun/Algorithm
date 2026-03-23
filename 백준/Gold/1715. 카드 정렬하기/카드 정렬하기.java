import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    static int n;
    static PriorityQueue<Integer> pq = new PriorityQueue<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++){
            pq.add(Integer.parseInt(br.readLine()));
        }
        int sum = 0;
        while(pq.size() > 1){
            int a = pq.poll();
            int b = pq.poll();
            sum += a + b;
            pq.add(a + b);
        }
        System.out.println(sum);
    }
}
