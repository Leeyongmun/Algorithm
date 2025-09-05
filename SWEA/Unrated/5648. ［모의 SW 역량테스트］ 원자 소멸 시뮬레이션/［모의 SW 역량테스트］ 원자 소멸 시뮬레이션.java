import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Solution {
    static int T, n;
    static ArrayList<Atom> atom;
    static int[] dy = {-1, 1, 0, 0};
    static int[] dx = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int t = 1; t <= T; t++){
            n = sc.nextInt();
            atom = new ArrayList<>();
            for(int i = 0; i < n; i++){
                int x = sc.nextInt() * 2;
                int y = sc.nextInt() * 2;
                int dir = sc.nextInt();
                int e = sc.nextInt();
                atom.add(new Atom(y, x, dir, e));
            }
            atom.sort((a, b) -> {
                if(a.x == b.x){
                    return a.y - b.y;
                }
                return a.x - b.x;
            });

            System.out.println("#" + t + " " + makeBoom());    
        }
    }

    private static int makeBoom(){
        ArrayList<Pair> boom = new ArrayList<>();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                Atom a = atom.get(i);
                Atom b = atom.get(j);
                if(a.x == b.x){
                    if(a.d == 0 && b.d == 1){
                        boom.add(new Pair(i, j, Math.abs(a.y - b.y) / 2));
                    }
                }
                if(a.y == b.y){
                    if(a.d == 3 && b.d == 2){
                        boom.add(new Pair(i, j, Math.abs(a.x - b.x) / 2));
                    }
                }
                if(a.x - a.y == b.x - b.y){
                    if((a.d == 3 && b.d == 1) || (a.d == 0 && b.d == 2)){
                        boom.add(new Pair(i, j, Math.abs(a.x-b.x)));
                    }
                }
                if(a.x + a.y == b.x + b.y){
                    if((a.d == 1 && b.d == 2) || (a.d == 3 && b.d == 0)){
                        boom.add(new Pair(i, j, Math.abs(a.x-b.x)));
                    }
                }
            }
        }
        return getTotalEnergy(boom);
    }

    private static int getTotalEnergy(ArrayList<Pair> boom){
        boom.sort(Comparator.comparingInt(b -> b.time));
        int boomtime[] = new int[n];
        Arrays.fill(boomtime, 987654321);
        int sum = 0;

        for(Pair p : boom){
            if(boomtime[p.i] < p.time || boomtime[p.j] < p.time) continue;
            if(boomtime[p.i] == 987654321){
                boomtime[p.i] = p.time;
                sum += atom.get(p.i).e;
            }
            if(boomtime[p.j] == 987654321){
                boomtime[p.j] = p.time;
                sum += atom.get(p.j).e;
            }
        }
        return sum;
    }


    static class Atom{
        int y, x, d, e;
        Atom(int y, int x, int d, int e){
            this.y = y;
            this.x = x;
            this.d = d;
            this.e = e;
        }
    }

    static class Pair{
        int i, j, time;
        Pair(int i, int j, int time){
            this.i = i;
            this.j = j;
            this.time = time;
        }
    }
}
