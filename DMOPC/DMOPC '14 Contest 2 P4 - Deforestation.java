import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Deforestation {
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
    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);
        int n = sc.nextInt();
        int[] mass = new int[n + 1];
        for (int i = 1; i <= n; i++)
            mass[i] = sc.nextInt();
        int[] pi = new int[n + 1];
        pi[1] = mass[1];
        for (int i = 2; i <= n; i++)
            pi[i] = pi[i - 1] + mass[i];
        int q = sc.nextInt();
        for (int i = 1; i <= q; i++) {
            int a = sc.nextInt() + 1;
            int b = sc.nextInt() + 1;
            System.out.println(pi[b] - pi[a - 1]);
        }
    }
}