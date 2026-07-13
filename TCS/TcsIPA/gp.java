import java.util.Scanner;

public class Main  {
   public static void main(String[] args)  {
        Scanner sc=new Scanner(System.in);
            int t=sc.nextInt();
             int n=sc.nextInt();
             int cr=sc.nextInt();

        while(n!=0){
          
          System.out.println(t);
          t=t*cr;
          n--;
        }
     sc.close();

   }}
