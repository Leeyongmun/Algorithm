import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static String s;
    static String[] a;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        s = sc.next();
        a = new String[s.length()];
        for(int i = 0; i < s.length(); i++){
            a[i] = s.substring(i);
        }
        Arrays.sort(a);
        for(int i = 0; i < s.length(); i++){
            System.out.println(a[i]);
        }
    }
}
