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

        String input = sc.nextLine();
        ArrayList word = new ArrayList();

        while (!input.equals("X")) {
            do {
                input = input.replaceAll("BAS", "A");
                input = input.replaceAll("ANA", "A");
            }
            while (input.contains("ANA") || input.contains("BAS"));

            if (input.equals("A")) word.add("YES");
            else word.add("NO");

            input = sc.nextLine();
        }

        for (int i = 0; i < word.size(); i++) {
            System.out.println(word.get(i));
        }
    }
}