/* Given a string and check whether its palindrome or not. A palindrome string is a string which is same even after reverseing the string.
This code is uses non-case sensitive comparing which means capital and small letter will be treated same.
Examples : 
Input: - Enter the String:
       - MaaM

Output: a palindrome string
*/

import java.util.Scanner;
class PalindromeString {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String s1, s2 = "";
        System.out.println("Enter a string:");
        s1 = sc.nextLine();
        int l = s1.length();
        for (int i = 0; i < l; i++) {
            char ch = s1.charAt(i);
            s2 = ch + s2;
        }
        if (s1.equalsIgnoreCase(s2) == true) {
            System.out.println("A palindrome string");
        } else {
            System.out.println("Not a palindrome string");
        }
    }
}