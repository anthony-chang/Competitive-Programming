import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = 0, y = 0, inputX, inputY, c, r;
        ArrayList xPos = new ArrayList();
        ArrayList yPos = new ArrayList();
        c = sc.nextInt();
        r = sc.nextInt();
        inputX = sc.nextInt();
        inputY = sc.nextInt();
        while (inputX != 0 || inputY != 0) {
            x += inputX;
            if (x > c) x = c;
            else if (x < 0) x = 0;
            xPos.add(x);

            y += inputY;
            if (y > r) y = r;
            else if (y < 0) y = 0;
            yPos.add(y);

            inputX = sc.nextInt();
            inputY = sc.nextInt();
        }
        for (int i = 0; i < xPos.size(); i++) {
            System.out.print(xPos.get(i));
            System.out.println(" " + yPos.get(i));
        }

    }
}