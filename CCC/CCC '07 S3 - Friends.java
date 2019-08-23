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
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       
        int n = sc.nextInt(), x, y, seperation = -1;
        int[] assf = new int[10000];
        boolean[] circle = new boolean[10000];
        for (int i = 1; i < n + 1; i++) {
            assf[sc.nextInt()] = sc.nextInt();
        }
        x = sc.nextInt();
        y = sc.nextInt();
        while (x!= 0 && y != 0) {
            do {
                circle[x] = true;
                x = assf[x];
                seperation++;
            }
            while (y != x && !circle[x]);
            //System.out.println("Separation: " + seperation);
            if (x == y) System.out.println("Yes " + seperation);
            else System.out.println("No");

            seperation = -1;
            Arrays.fill(circle, false);

            x = sc.nextInt();
            y = sc.nextInt();
        }




    }
}