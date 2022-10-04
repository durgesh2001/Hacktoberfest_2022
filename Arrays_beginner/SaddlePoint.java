/* Given a matrix of n x n size, the task is to find the saddle point of the matrix. A saddle point is an element of the matrix such that it is the minimum element in its row and the maximum in its column. 
Examples : 
Input: - Enter the matrix size:
       - 3
       - Enter the value:
       - 1 2 3 4 5 6 7 8 9
Output: 7
7 is minimum in its row and maximum in its column.
Input: - Enter the matrix size:
       - 3
       - Enter the value:
       - 1 2 3 4 5 6 10 18 4
Output: No saddle point */

import java.util.*;
class SaddlePoint {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n, j, i, k, max, f = 0, min, c;
        System.out.println("Enter matrix size:");
        n = sc.nextInt();
        int a[][] = new int[n][n];
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                System.out.println("Enter the value:");
                a[i][j] = sc.nextInt();
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
        for (i = 0; i < n; i++) {
            min = a[i][0];
            c = 0;
            for (j = 0; j < n; j++) {
                if (a[i][j] < min) {
                    min = a[i][j];
                    c = j;
                }
            }
            max = a[0][c];
            for (k = 0; k < n; k++) {
                if (a[k][c] > max) {
                    max = a[k][c];
                }
            }
            if (max == min) {
                System.out.println("Saddle Point - " + max);
                f = 1;
            }
        }
        if (f == 0) {
            System.out.println("No Saddle Point in the Matrix");
        }
    }
}
