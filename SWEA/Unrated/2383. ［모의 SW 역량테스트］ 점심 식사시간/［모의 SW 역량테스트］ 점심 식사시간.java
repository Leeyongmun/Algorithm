import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Solution {
    static int T, n;
    static int[][] map;
    static ArrayList<Pair> people = new ArrayList<>();
    static ArrayList<Pair> stair = new ArrayList<>();
    static int ret = 987654321;
    static PriorityQueue<Integer> pq1;
    static PriorityQueue<Integer> pq2;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            people = new ArrayList<>();
            stair = new ArrayList<>();
            ret = 987654321;
            n = sc.nextInt();
            map = new int[n][n];
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    map[i][j] = sc.nextInt();
                    if(map[i][j] == 1){
                        people.add(new Pair(i, j));
                    }
                    else if(map[i][j] != 0){
                        stair.add(new Pair(i, j));
                    }
                }
            }
            for(int mask = 0; mask < (1 << people.size()); mask++){
                pq1 = new PriorityQueue<>();
                pq2 = new PriorityQueue<>();
                Pair s1 = stair.get(0);
                Pair s2 = stair.get(1);
                int k1 = map[s1.y][s1.x];
                int k2 = map[s2.y][s2.x];
                make(mask);
                int time = Math.max(simulation(pq1, k1), simulation(pq2, k2));
                ret = Math.min(ret, time);
            }
            System.out.println("#" + t + " " + ret);
        }
    }

    private static void make(int mask){
        Pair s1 = stair.get(0);
        Pair s2 = stair.get(1);

        for(int i = 0; i < people.size(); i++){
            Pair p = people.get(i);
            if((mask & (1 << i)) != 0){
                pq1.offer((Math.abs(s1.y - p.y) + Math.abs(s1.x - p.x)) + 1);
            }
            else{
                pq2.offer((Math.abs(s2.y - p.y) + Math.abs(s2.x - p.x)) + 1);
            }
        }
    }

    private static int simulation(PriorityQueue<Integer> pq, int k){
        int time = 0;
        Deque<Integer> d = new ArrayDeque<>();
        while(!(d.isEmpty() && pq.isEmpty())){
            time++;
            int dSize = d.size();
            for(int i = 0; i < dSize; i++){
                int t = d.pollFirst();
                if(t - 1 == 0) continue;
                d.addLast(t - 1);
            }

            while(d.size() < 3 && !pq.isEmpty() && time >= pq.peek()){
                pq.poll();
                d.addLast(k);
            }
        }
        return time;
    }

    static class Pair{
        int y, x;
        Pair(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
}
