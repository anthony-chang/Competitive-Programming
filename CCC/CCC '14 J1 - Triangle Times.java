import java.util.Scanner;
import java.util.Arrays;

public class HelloWorld {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int ang1, ang2, ang3;
		ang1 = sc.nextInt();
		ang2 = sc.nextInt();
		ang3 = sc.nextInt();
		
		if (ang1 + ang2 + ang3 == 180)	{
			if (ang1 == ang2 && ang2 == ang3)	{
				System.out.println("Equilateral");
			}
			else if (ang1 == ang2 || ang1 == ang3 || ang2 == ang3)	{
				System.out.println("Isosceles");
			}
			else	{
				System.out.println("Scalene");
			}
		}
		else {
			System.out.println("Error");
		}
		
	}

}