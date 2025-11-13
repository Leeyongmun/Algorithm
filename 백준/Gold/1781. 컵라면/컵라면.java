import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static int n;
    static ArrayList<Node> a = new ArrayList<>();
    static PriorityQueue<Integer> pq = new PriorityQueue<>();

    static class Node{
        int day, cup;
        Node(int day, int cup){
            this.day = day;
            this.cup = cup;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            a.add(new Node(x, y));
        }
        a.sort((r1, r2) -> {
            return r1.day - r2.day;
        });

        for(int i = 0; i < n; i++){
            pq.add(a.get(i).cup);

            if(pq.size() > a.get(i).day){
                pq.poll();
            }
        }
        long ret = 0;
        while(!pq.isEmpty()) ret += pq.poll();
        System.out.println(ret);
    }
}
