import java.util.Scanner;
import java.util.Arrays;

public class HelloWorld {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int y, m, o;
		y= sc.nextInt();
		m= sc.nextInt();
		o = (m-y)+m;
		System.out.println(o);
	}

}