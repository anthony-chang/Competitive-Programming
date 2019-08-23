import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Bombing {
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

    public static void main(String[] args) throws IOException {
        FastScanner sc = new FastScanner(System.in);
        int[][]p = new int[26][26];
        int n = 0;
        ArrayList<String> r = new ArrayList<>();
        String str = sc.nextLine();
        while (!str.equals("**")) {
            r.add(str);
            str = sc.nextLine();
        }

        for (int i = 0; i < r.size(); i++) {
            for (int[] e: p)
                Arrays.fill(e, 1);
            for (int j = 0; j < 26; j++)
                p[j][j] = 0;
            for (int j = 0; j < r.size(); j++) {
                if (j != i) {
                    int a = r.get(j).charAt(0) - 65;
                    int b = r.get(j).charAt(1) - 65;
                    p[a][b] = 0;
                    p[b][a] = 0;
                }
            }
            for (int x = 0; x < 26; x++)
                for (int y = 0; y < 26; y++)
                    if (p[y][x] == 0)
                        for (int z = 0; z < 26; z++)
                            if (p[x][z] == 0)
                                p[y][z] = 0;
            if (p[0][1] == 1) {
                System.out.println(r.get(i));
                n++;
            }
        }
        System.out.println("There are "+n+" disconnecting roads.");



    }
}