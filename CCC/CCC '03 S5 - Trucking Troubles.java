import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class TruckingTroubles {
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
        int N = sc.nextInt(), M = sc.nextInt(), D = sc.nextInt();
        ArrayList<P> adj[] = new ArrayList[N + 1];
        for (int i = 0; i <= N; i++)
            adj[i] = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            int x = sc.nextInt(), y=sc.nextInt(), z = sc.nextInt();
            adj[x].add(new P(y, z));
            adj[y].add(new P(x, z));
        }
        int[] dis  = new int[N + 1];
        boolean[] des = new boolean[N + 1];
        for (int i = 0; i < D; i++)
            des[sc.nextInt()] = true;
        PriorityQueue<P> q = new PriorityQueue<>();
        q.add(new P(1, Integer.MAX_VALUE));
        dis[1] = Integer.MAX_VALUE;
        while (!q.isEmpty()) {
            P cur = q.poll();
            if (cur.w < dis[cur.v])
                continue;
            for (P e: adj[cur.v]) {
                if (dis[e.v] < e.w) {
                    dis[e.v] = e.w;
                    q.add(new P(e.v, dis[e.v]));
                }
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 1; i <= N; i++)
            if (des[i]) ans = Math.min(ans, dis[i]);
        System.out.println(ans);
    }
    static class P implements Comparable<P>{
        int v, w;
        P(int v0, int w0) {
            v = v0; w = w0;
        }
        public int compareTo (P x) {
            return Integer.compare(x.w, w);
        }
    }
}