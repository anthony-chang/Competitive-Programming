import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Gates {
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

        int[] g = new int[sc.nextInt() + 1];
        int p = sc.nextInt();
        int ans = 0;
        for (int i = 0; i < p; i++) {
            int cur = sc.nextInt();
            while (cur > 0 && g[cur] > 0) {
                int temp = g[cur];
                g[cur]++;
                cur = cur - temp;
            }
            if (cur < 1)
                break;
            else {
                g[cur] = 1;
                ans++;
            }
        }
        System.out.println(ans);

    }
}