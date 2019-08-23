import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(sc.readLine());
        int input, highestF, secondF, output;
        int[] mostFReadings = new int[1001];
        int[] secondMFReadings = new int[1001];
        int[] frequency = new int[1001];



        for (int i = 0; i < n; i++) {
            input = Integer.parseInt(sc.readLine());
            frequency[input]++;
        }

        int[] maxFreq = frequency.clone();
        Arrays.sort(maxFreq);
        highestF = maxFreq[maxFreq.length - 1];
        secondF = maxFreq[maxFreq.length - 2];


        for (int i = 0; i < 1001; i++) {
            if (frequency[i] == highestF) mostFReadings[i] = i;
            if (frequency[i] == secondF) secondMFReadings[i] = i;
        }
        Arrays.sort(mostFReadings);
        Arrays.sort(secondMFReadings);

        output = Math.abs(mostFReadings[mostFReadings.length - 1] - secondMFReadings[secondMFReadings.length - 1]);
        for (int i = 1000; i >= 0; i--) {
            if (Math.abs(mostFReadings[mostFReadings.length - 1] - secondMFReadings[i]) > output && secondMFReadings[i] != 0) {
                output = Math.abs(mostFReadings[mostFReadings.length - 1] - secondMFReadings[i]);
            }
        }

        System.out.println(output);

    }
}