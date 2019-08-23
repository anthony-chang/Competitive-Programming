import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
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
        int n = sc.nextInt(), m = sc.nextInt();
        ArrayList<E>[] dj = new ArrayList[n+1];
        for(int i = 0; i <= n; i++) {
            dj[i] = new ArrayList<E>();
        }
        for(int i = 1; i <= m; i++) {
            int x = sc.nextInt(), y = sc.nextInt(), z = sc.nextInt();
            dj[x].add(new E(y, z, 1)); 
            dj[y].add(new E(x, z, 1));
        }
        int[] dis = new int[n+1];
        int[] dang = new int[n+1];
        Arrays.fill(dis, Integer.MAX_VALUE);
        PriorityQueue<E> Q = new PriorityQueue<>();
        Q.add(new E(1, 0, 0)); 
        dis[1] = 0; 
        dang[1] = 0;
        
        while(!Q.isEmpty()) {
            E cur = Q.poll();
            if(cur.w > dis[cur.v]) continue;
            for(E e: dj[cur.v]) {
                if (dis[e.v] > dis[cur.v] + e.w) {
                    dis[e.v] = dis[cur.v] + e.w;
                    dang[e.v] = dang[cur.v] + e.n;
                    Q.add(new E(e.v, dis[e.v], dang[e.v]));
                }
                else if(dis[e.v] == dis[cur.v] + e.w && dang[e.v] > dang[cur.v] + e.n){
                    dang[e.v] = dang[cur.v] + e.n;
                    Q.add(new E(e.v, dis[e.v], dang[e.v]));
                }
            }
        }
        if(dis[n] == Integer.MAX_VALUE) System.out.println(-1);
        else System.out.println(dis[n] + " " + dang[n]);
    }

    static class E implements Comparable<E>{
        int v, w, n;
        E(int a, int b, int c) {
            v = a; w = b; n = c;
        }

        public int compareTo(E x) {
            if(x.w > w)
                return -1;
            else if (x.w < w)
                return 1;
            else {
                if(x.n > n)
                    return -1;
                else
                    return 1;
            }
        }
    }
}