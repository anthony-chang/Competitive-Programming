import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 0;
        String str = sc.nextLine();
        if (str.equals("green")||str.equals("red")||str.equals("white")) 
        	n++; 
        str = sc.nextLine(); 
        if (str.equals("green")||str.equals("red")||str.equals("white")) 
        	n++;
        if (n < 2)    
        	System.out.println("Boring..."); 
        else 
        	System.out.println("Jingle Bells");

    }
}