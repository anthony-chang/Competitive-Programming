import java.util.Scanner;
import java.util.Arrays;

public class HelloWorld {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int quarters, mach1, mach2, mach3, plays;
		
		quarters = sc.nextInt();
		mach1 = sc.nextInt();
		mach2 = sc.nextInt();
		mach3 = sc.nextInt();
		plays = 1;
		
		while (quarters>0)	{
			
			quarters--;			
			mach1++;
			if (mach1 == 35)	{
				quarters += 30;
				mach1=0;
			}
			plays++;
		
					
			quarters--;
			if (quarters < 1)	{
				break;
			}
			
			mach2++;
			if (mach2 == 100)	{
				quarters += 60;
				mach2=0;
			}
			plays++;
			
			quarters--;
			if (quarters < 1)	{
				break;
			}
			
			mach3++;
			if (mach3 == 10)	{
				quarters += 9;
				mach3 =0; 
			}
			plays++;
		}
		
		System.out.println("Martha plays " + plays + " times before going broke.");
		
		
	}
