import java.util.Scanner;
import java.util.Arrays;

public class HelloWorld {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int size;
		int i=0;
		size = sc.nextInt();
		int[] anArray1;
		
		anArray1 = new int [size];
		
		while (i<size)	{
			anArray1[i] = sc.nextInt();
			i++;
		}
		
		Arrays.sort(anArray1);
		for (int n=0; n<size; n++)	{
			System.out.println(anArray1[n]);
		}
	}

}