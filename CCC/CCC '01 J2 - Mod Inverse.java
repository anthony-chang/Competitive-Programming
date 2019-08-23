import java.util.Scanner;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner (System.in);
		
		int x, m;
		x = sc.nextInt();
		m = sc.nextInt();
		
		for (int i = 0; i<=101; i++)	{
			if (((i * x))%m == 1)	{
				System.out.println(i);
				break;				
			}
			if (i==101){
				
					System.out.println("No such integer exists.");
				
			}
		}
		
	}

}