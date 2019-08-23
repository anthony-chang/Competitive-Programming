import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        double[] x = new double[n];
        double[] y = new double[n];
        double a, b, c, semiP = 0, diameter, output = 0;
        double tri1, tri2, tri3;
        for (int i = 0; i < n; i++) {
            x[i] = sc.nextDouble();
            y[i] = sc.nextDouble();
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    a = Math.sqrt(Math.pow(x[i] - x[j], 2) + Math.pow(y[i] - y[j], 2));
                    b = Math.sqrt(Math.pow(x[j] - x[k], 2) + Math.pow(y[j] - y[k], 2));
                    c = Math.sqrt(Math.pow(x[k] - x[i], 2) + Math.pow(y[k] - y[i], 2));
                    semiP = (a + b + c) / 2;
                    diameter = 0;

                    tri1 = (a * a) + (b * b) - (c * c);
                    tri2 = (b * b) + (c * c) - (a * a);
                    tri3 = (a * a) + (c * c) - (b * b);

                    if (tri1 < 0 || tri2 < 0 || tri3 < 0 || semiP == 0) {
                        if (a > diameter) diameter = a;
                        if (b > diameter) diameter = b;
                        if (c > diameter) diameter = c;
                    }
                    else {
                        diameter = (a * b * c);
                        diameter /= (4 * Math.sqrt (semiP * (semiP - a) * (semiP - b) * (semiP - c)));
                        diameter *= 2;
                    }

                    if (diameter > output) output = diameter;
                }


        System.out.printf("%f", output);
    }
}