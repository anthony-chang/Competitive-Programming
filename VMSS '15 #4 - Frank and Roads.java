import java.util.*;
import java.io.*;

public class FrankAndRoads {
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

    static class E implements Comparable<E>{
        int v, w;
        E(int x, int y) {
            v = x;
            w = y;
        }
        public int compareTo(E x) {
            return Integer.compare(w, x.w);
        }
    }
    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);

        int t = sc.nextInt();
        int n = sc.nextInt() + 1;
        int m = sc.nextInt();
        int g = sc.nextInt();
        int[] foodBasics = new int[g + 1];
        for (int i = 0; i < g; i++) {
            foodBasics[i] = sc.nextInt();
        }
        ArrayList<E> [] dj = new ArrayList[n];
        for (int i = 0; i < n; i++)
            dj[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            dj[u].add(new E(v, w));
        }
        int[] dis = new int[n];
        Arrays.fill(dis, Integer.MAX_VALUE);
        PriorityQueue<E> q = new PriorityQueue<>();

        q.add(new E(0, 0));
        dis[0] = 0;
        while (!q.isEmpty()) {
            E cur = q.poll();
            if (cur.w > dis[cur.v])
                continue;
            for (E e : dj[cur.v]) {
                if (dis[e.v] > dis[cur.v] + e.w) {
                    dis[e.v] = dis[cur.v] + e.w;
                    q.add(new E(e.v, dis[e.v]));
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < g; i++) {
            if (dis[foodBasics[i]] <= t )
                ans++;
        }
        System.out.println(ans);

    }
}