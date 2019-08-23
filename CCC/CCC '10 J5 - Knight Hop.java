import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class KnightsHop {
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
    public static void main(String[] args) throws IOException{
        FastScanner sc = new FastScanner(System.in);
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int x1 = sc.nextInt();
        int y1 = 9 - sc.nextInt();
        int x2 = sc.nextInt();
        int y2 = 9-sc.nextInt();
        ArrayList<E>[] dj = new ArrayList[65];
        for (int i = 1; i < 65; i++)
            dj[i] = new ArrayList<>();
        for (int r = 1; r < 9; r++) {
            for (int c = 1; c < 9; c++) {
                int i = (r - 1) * 8 + c;
                if (i > 10 && r > 1 && c > 2)
                    dj[i].add(new E(i - 10, 1));
                if (i > 17 && r > 2 && c > 1)
                    dj[i].add(new E(i - 17, 1));
                if (i > 6 && r > 1 && c < 7)
                    dj[i].add(new E(i - 6, 1));
                if (i > 15 && r > 2 && c < 8)
                    dj[i].add(new E(i - 15, 1));
                if (i + 6 < 65 && r < 8 && c > 2)
                    dj[i].add(new E(i + 6, 1));
                if (i + 15 < 65 && r < 7&& c > 1)
                    dj[i].add(new E(i + 15, 1));
                if (i + 17 < 65 && r < 7 && c < 8)
                    dj[i].add(new E(i + 17, 1));
                if (i + 10 < 65 && c < 7 && r < 8)
                    dj[i].add(new E(i + 10, 1));
            }
        }
        int[] dis = new int[65];
        Arrays.fill(dis, Integer.MAX_VALUE);
        PriorityQueue<E> q = new PriorityQueue<>();
        int start = (y1-1) * 8 + x1;
        int end = (y2-1) * 8 + x2;

        q.add(new E(start, 0));
        dis[start] = 0;
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
        System.out.println(dis[end]);

    }
}