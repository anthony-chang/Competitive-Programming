import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class ting {
    static class FastScanner {
        private BufferedReader br;
        private StringTokenizer st;

        public FastScanner (InputStream in){
            br = new BufferedReader(new InputStreamReader(in));
            st = new StringTokenizer("");
        }
        private String next() throws IOException {
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
    public static void main(String[] args) throws IOException{
        FastScanner sc = new FastScanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (a == b)
            System.out.println("GO SHAHIR!");
        else {
            int[][] road = new int[n + 1][n + 1];
            for (int i = 1; i <= m; i++) {
                int x = sc.nextInt();
                int y = sc.nextInt();
                road[x][y] = 1;
                road[y][x] = 1;
            }
            Queue<Integer> q = new LinkedList();
            q.add(a);
            boolean[] vis = new boolean[n + 1];
            vis[a] = true;
            boolean ans = false;
            while (!q.isEmpty()) {
                int u = q.remove();
                for (int i = 1; i <= n; i++) {
                    if (road[i][u] == 1 && !vis[i]) {
                        q.add(i);
                        //System.out.println(i);
                        vis[i] = true;
                        if (i == b) {
                            ans = true;
                            break;
                        }
                    }

                }
            }
            if (ans)
                System.out.println("GO SHAHIR!");
            else
                System.out.println("NO SHAHIR!");
        }

    }
}