import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class FastScanner {
        private BufferedReader br;
        private StringTokenizer st;
        FastScanner(InputStream in) {
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

    
    private static int p[];
    private static int find(int x) {
        if (x!= p[x])
            p[x] = find(p[x]);
        return p[x];
    }
    private static void union(int u, int v) {
        p[u] = v;
    }
    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), count = 0;
        ArrayList<Integer> arrL = new ArrayList<>();
        p = new int[n + 1];
        for (int i = 1; i <= n; i++)
            p[i] = i;
        for (int i = 1; i <= m; i++) {
            int a = sc.nextInt(), b = sc.nextInt();
            int fa = find(a), fb = find(b);
            if (fa != fb) {
                union(fa, fb);
                count++;
                arrL.add(i);
            }
            if (count == n-1) 
                break;
        }
        if (count == n-1) {
            for (int u: arrL)
                System.out.println(u);
        } else 
            System.out.println("Disconnected Graph");
        
        

    }
}