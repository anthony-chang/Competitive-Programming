import java.util.*;
import java.io.*;

public class Main {
    static class FastScanner {
        private BufferedReader br;
        private StringTokenizer st;

        public FastScanner (InputStream in){
            br = new BufferedReader(new InputStreamReader(in));
            st = new StringTokenizer("");
        }
        public String next() throws IOException {
            if (st.hasMoreTokens()) return st.nextToken();
            else st = new StringTokenizer(br.readLine());
            return next();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }
        public String nextLine() throws IOException {
            if (!st.hasMoreTokens()) return br.readLine();
            String cont = st.nextToken();
            while (st.hasMoreTokens()) {
                cont += " " + st.nextToken();
            }
            return cont;
        }
    }


    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);

        int n = sc.nextInt(), ans = 0;
        char[][] troll = new char[n][n];
        int[][] dp =new int[n][n];

        for (int i = 0; i < n; i++) {
            String str = sc.nextLine();
            for (int j = 0; j < n; j++)
                troll[i][j] = str.charAt(j);
        }

        //last row
        for (int c = 0; c < n; c++) {
            if (troll[n - 1][c] == '#') dp[n - 1][c] = 1;
            else dp[n - 1][c] = 0;
        }

        //first and last column
        for (int r = 0; r < n; r++) {
            if (troll[r][0] == '#') dp[r][0] = 1;
            if (troll[r][n - 1] == '#') dp[r][n - 1] = 1;
        }
        for (int r = n - 2; r >= 0; r--) {
            for (int c = 1; c < n - 1; c++) {
                    if (troll[r][c] == '.') {
                        dp[r][c] = 0;
                    }
                    else if (troll[r][c] == '#'){
                        dp[r][c] = Math.min(dp[r + 1][c - 1], Math.min(dp[r + 1][c], dp[r + 1][c + 1])) + 1;
                    }
            }
        }
         for (int i = 0; i < n; i++)
             for (int j = 0; j < n; j++)
                 //System.out.println(dp[i][j]);
                 ans += dp[i][j];

        System.out.println(ans);
    }
}