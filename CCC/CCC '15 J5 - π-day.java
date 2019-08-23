import java.util.*;

public class PiDY {

    static int[][] arr = new int[251][251];
    static int pi(int n, int k) {
        if (n < k)
            return 0;
        else if (k == 1 || k == n)
            return 1;
        else if (arr[n][k] != 0)
            return arr[n][k];
        arr[n][k] = pi(n - 1, k - 1) + pi(n - k, k);
        return arr [n][k];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        System.out.println(pi(n, k));


    }
}