import java.util.Scanner;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner (System.in);
		
		
		
		String input;
		input = sc.nextLine();
		
		do	{
			if (input.equals("quit!"))	{
				break;
			}
			else if (input.length()<4)	{
				System.out.println(input);
			}
			else if (input.endsWith("or") && !input.endsWith("aor") && !input.endsWith("eor") && !input.endsWith("ior") && !input.endsWith("oor") && !input.endsWith("uor") && !input.endsWith("aor"))
			{
				input = input.replace("or", "our");
				System.out.println(input);			
								
			}
			
			else	{
				System.out.println(input);
				
			}
			input = sc.nextLine();
			
		}while (!input.equals("quit!"));
		
		
		
		
		
	}

}