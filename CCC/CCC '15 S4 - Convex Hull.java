import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class ConvexHull {
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

    static class E implements Comparable<E>{
        int v, w, dmg;
        E(int x, int y, int z) {
            v = x;
            w = y;
            dmg = z;
        }
        public int compareTo(E x) {
            int n = Integer.compare(w, x.w);
//            if (n == 0)
//                return Integer.compare(dmg, x.dmg);
            return n;
        }
    }
    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);

        int k = sc.nextInt(), n = sc.nextInt(), m = sc.nextInt();
        ArrayList<E> [] dj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++)
            dj[i] = new ArrayList<>();
        for (int i = 1; i <= m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            int h = sc.nextInt();
            dj[u].add(new E(v, w, h));
            dj[v].add(new E(u, w, h));
        }
        int a = sc.nextInt(), b= sc.nextInt();
        int[][] dis = new int[2002][201];
        for (int[] i: dis)
            Arrays.fill(i, 999999999);
        boolean[] vis = new boolean[2002];

        PriorityQueue<E> q = new PriorityQueue<>();

        q.add(new E(a, 0, 0));
        dis[a][0] = 0;
        vis[a] = true;
        while (!q.isEmpty()) {
            E cur = q.poll();

            for (int i = 0; i < dj[cur.v].size(); i++) {
                ArrayList<E> es = dj[cur.v];
                E e = es.get(i);
                for (int j = 0; j + e.dmg < k; j++) {
                    if (dis[e.v][j + e.dmg] > dis[cur.v][j] + e.w) {
                        dis[e.v][j + e.dmg] = dis[cur.v][j] + e.w;
                        if (!vis[e.v]) {
                            q.add(new E(e.v, dis[e.v][j + e.dmg], e.dmg));
                            vis[e.v] = true;
                        }
                    }
                }
                vis[e.v] = false;
            }
        }

        int ans = 999999999;
        for (int i = 0; i < k; i++) {
            ans = Math.min(ans, dis[b][i]);
        }
        if (ans == 999999999)
            System.out.println(-1);
        else
            System.out.println(ans);



    }
}