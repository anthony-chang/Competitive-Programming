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

        int M = sc.nextInt();
        int input, uniques = 0;
        boolean [] percent = new boolean[101];
        int counter = 0, ans = 100;
        for (int i = 0; i < M; i++) {
            input = sc.nextInt();
            if (percent[input] == false) {
                percent[input] = true;
                uniques++;
            }
        }

        for (int denom = 1; denom < 1000; denom++) {
            for (int num = 0; num <= denom; num++) {
                long percentage = Math.round((double) num * 100.0 /denom);
                if (percent[(int) percentage]) {
                    counter++;
                }
            }
            if (counter == uniques && denom <= ans) {
                ans = denom;
                break;
            }
            counter = 0;
        }
        System.out.println(ans);
    }
}