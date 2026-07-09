import java.util.Scanner;

public class bank {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double balance = 0;
        boolean isRunning = true;
        int choice;

        while (isRunning) {
            //DECLARE VARIABLES
            //DISPLAY MENU
            System.out.println("*******************");
            System.out.println("1. Show Balance");
            System.out.println("2. Deposit");
            System.out.println("3. Withdraw");
            System.out.println("4. Exit");
            System.out.println("********************");

            System.out.print("Enter your choice (1-4): ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1 -> Showbalance(balance);
                case 2 -> balance = balance + Deposit();
                case 3 -> balance = balance - Withdraw(balance);
                case 4 -> isRunning = false;
                default -> System.out.println("INVALID CHOICE");
            }


            //GET AND PROCESS USERS CHOICE
            //SHOWBALANCE
            //DEPOSIT
            //WITHDRAW
            //EXIT MESSAGE()

        }
        System.out.println("Thank you");
        scanner.close();
    }

    static void Showbalance(double balance) {
        System.out.println("********************");
        System.out.printf("$%.2f\n", balance);
    }

    static double Deposit() {
        double amount;
        System.out.print("Enter an amount to deposit");
        amount = scanner.nextDouble();

        if (amount < 0) {
            System.out.println("amount can be nagative");
            return 0;
        } else {
            return amount;
        }
    }

    static double Withdraw(double balance) {
        double amount;
        System.out.print("Enter amount to be withdrawn: ");
        amount = scanner.nextDouble();

        if (amount > balance) {
            System.out.println("insuffuicint funds");
            return 0;
        } else if (amount < 0) {
            System.out.println("Amount can't be negative");
            return 0;
        } else {
            return amount;
        }
    }
}

