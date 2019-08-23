import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BIT {
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
    static class B {
        long[] BITree;

        public B(int size) {
            BITree = new long[size];
        }
        long sum(long index) {
            long sum = 0;
            index++;
            while (index > 0) {
                sum += BITree[(int) index];
                index -= index & (-index);
            }
            return sum;
        }

        void update(int n, long index, long val) {
            index++;
            while (index <= n) {
                BITree[(int) index] += val;
                index += index & (-index);
            }
        }

        void construct(long arr[], int n) {
            for (int i = 0; i < n; i++)
                update(n, i, arr[i]);
        }
    }
    public static void main(String args[]) throws IOException{
        FastScanner sc = new FastScanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        long[] input = new long[n];
        B bit = new B(n + 1);

        long[] freq = new long[100001];
        B bFreq = new B(100002);

        for (int i = 0; i < n; i++) {
            input[i] = sc.nextLong();
            freq[(int)input[i]]++;
        }

        bit.construct(input, n);
        bFreq.construct(freq, 100001);


        for (int i = 0; i < m; i++) {
            char c = sc.next().charAt(0);
            if (c == 'C') {
                long ind = sc.nextLong() - 1;
                long val = sc.nextLong();
                long dif = val - input[(int)ind];

                //freq[(int)input[(int)ind]]--;
                //freq[(int)val]++;
                bFreq.update(100001, input[(int)ind], -1);
                bFreq.update(100001, val, 1);

                input[(int)ind] = val;
                bit.update(n, ind, dif);

            }
            else if (c == 'S') {
                long a = sc.nextLong() - 1;
                long b = sc.nextLong() - 1;
                System.out.println(bit.sum(b) - bit.sum(a - 1));
            }
            else if (c == 'Q') {
                System.out.println(bFreq.sum(sc.nextLong()));

            }

        }

    }
}