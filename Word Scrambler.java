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
    private static void anagram(String prefix, String str) {
        int n = str.length();
        if (n == 0) {
            System.out.println(prefix);
        }
        else {
            for (int i = 0; i < n; i++)
                anagram(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, n));
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);
        //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = sc.nextLine();
        char[] sort = input.toCharArray();
        //String[] output;
        Arrays.sort(sort);
        input = new String(sort);

        anagram("", input);



        //System.out.println(input);


    }
}