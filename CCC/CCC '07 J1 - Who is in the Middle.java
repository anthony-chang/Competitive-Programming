import java.util.Scanner;
import java.util.Arrays;

public class HelloWorld {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int []anArray;
		anArray = new int [3];
		anArray [0] = sc.nextInt();
		anArray [1] = sc.nextInt();
		anArray [2] = sc.nextInt();
		
		Arrays.sort(anArray);
		
		System.out.println(anArray[1]);
	}

}