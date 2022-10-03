/* Given a string and count size of smallest and largest word in sentence. Display them as well.
Examples : 
Input: - Enter the String:
       - This is a test string

Output: Largest word - string
        Frequency of word - 6
        Smallest word - a
        Frequency of word - 1
*/

import java.util.Scanner;
class WordType {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a String");
        String s1 = sc.nextLine();
        s1 = s1 + " ";
        String s2 = "", s3 = "", s4 = "";
        int i, l, max = 0, n = 0, p = 0;
        l = s1.length();
        int min = l;
        for (i = 0; i < l; i++) {
            char ch = s1.charAt(i);
            if (ch == ' ') {
                s2 = s1.substring(p, i);
                System.out.println(s2);
                n = s2.length();
                p = i + 1;
                System.out.println(s4);
            }
            if (n > max) {
                s3 = s2;
                max = n;
            }
            if (n < min) {
                s4 = s2;
                min = n;
            }
        }
        System.out.println("Largest word=" + s3);
        System.out.println("Frequency of word=" + max);
        System.out.println("Smallest word=" + s4);
        System.out.println("Frequency of word=" + min);
    }
}