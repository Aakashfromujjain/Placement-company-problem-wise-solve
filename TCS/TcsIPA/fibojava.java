import java.util.Scanner;

public class NMain {
    public static void main(String[] args)  {
        int a=-1,b=1;
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the no: ");
        int n = scanner.nextInt();

        while(n!=0){
            int c=a+b;
            System.out.print(" "+c);
            a=b;
            b=c;
            n--;
        }
        /*
        for(int i=0;i<n;i++)
        {
            int c=a+b;
            System.out.print(" " + c);
            a=b;
            b=c;
        }
        */
        scanner.close();
    }
}
