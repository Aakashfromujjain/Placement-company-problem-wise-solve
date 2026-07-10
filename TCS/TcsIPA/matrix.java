import java.util.*;

public class SpiralMatrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read matrix dimensions
        int m = sc.nextInt();
        int n = sc.nextInt();

        int[][] matrix = new int[m][n];

        // Read matrix elements
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

        // Boundaries
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        List<Integer> result = new ArrayList<>();

        // Spiral traversal
        while (top <= bottom && left <= right) {
            // Traverse left → right
            for (int i = left; i <= right; i++) {
                result.add(matrix[top][i]);
            }
            top++;

            // Traverse top → bottom
            for (int i = top; i <= bottom; i++) {
                result.add(matrix[i][right]);
            }
            right--;

            // Traverse right → left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.add(matrix[bottom][i]);
                }
                bottom--;
            }

            // Traverse bottom → top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.add(matrix[i][left]);
                }
                left++;
            }
        }

        // Print result
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
