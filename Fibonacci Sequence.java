import java.io.*;
import java.math.BigInteger;

public class Fib {
    private static BigInteger[] mat = {BigInteger.ONE, BigInteger.ONE, BigInteger.ONE, BigInteger.ZERO};
    private static BigInteger fibo(BigInteger n) {
        return exponent(mat, n)[1];

    }

    private static BigInteger[] exponent(BigInteger[] mat, BigInteger n) {
        BigInteger[] ans = {BigInteger.ONE, BigInteger.ZERO, BigInteger.ZERO, BigInteger.ONE};
        while (!n.equals(BigInteger.ZERO)) {
            if (!n.mod(BigInteger.valueOf(2)).equals(BigInteger.ZERO))
                ans = multiply(ans, mat);
            n = n.divide(BigInteger.valueOf(2));
            mat = multiply(mat, mat);
        }
        return ans;
    }
    private static BigInteger[] multiply(BigInteger[] a, BigInteger[] b) {
        return new BigInteger[]{
                a[0].multiply(b[0]).add(a[1].multiply(b[2])).mod(BigInteger.valueOf(1000000007)),
                a[0].multiply(b[1]).add(a[1].multiply(b[3])).mod(BigInteger.valueOf(1000000007)),
                a[2].multiply(b[0]).add(a[3].multiply(b[2])).mod(BigInteger.valueOf(1000000007)),
                a[2].multiply(b[1]).add(a[3].multiply(b[3])).mod(BigInteger.valueOf(1000000007))
        };
    }


    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        BigInteger n = new BigInteger(s);

        System.out.println(fibo(n));


    }
}