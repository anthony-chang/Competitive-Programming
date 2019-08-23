import java.util.Scanner;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner (System.in);
		
		
		int n, m;
		n = Integer.parseInt(sc.nextLine());
		m = Integer.parseInt(sc.nextLine());
		String [] adjective;
		String [] noun;
		
		adjective = new String [n];
		
		for (int i = 0; i<n; i++)	{
			//System.out.println("Adjective: " + i);
			adjective [i] = sc.nextLine();
		}
		
		
		noun = new String [m];
		
		for (int i = 0; i<m; i++)	{
			//System.out.println("Noun: " + i);
			noun [i] = sc.nextLine();
		}
		
		
		for (int i = 0; i < n; i++)	{			
			for (int j = 0; j < m; j++)	{
			System.out.print(adjective [i] + " as ");
			System.out.println(noun [j]);		
			}
		}
		
		
		
	}

}