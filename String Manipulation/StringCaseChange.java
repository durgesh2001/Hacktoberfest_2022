/* Given a string and change the Case of each character to its opposite like Lower case becomes Upper case and vise-versa.
Examples : 
Input: - Enter the String:
       - CaSe ChanGe

Output: cAsE cHANgE
*/

import java.io.*;
class StringCaseChange {
    public static void main(String args[]) throws IOException {
        int i, l;
        char ch;
        String str1 = " ";
        InputStreamReader reader = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(reader);
        System.out.println("Enter a string:");
        String str = br.readLine();
        l = str.length();
        for (i = 0; i < l; i++) {
            ch = str.charAt(i);
            if (ch >= 'A' && ch <= 'Z') {
                ch += 32;
            } else if (ch >= 'a' && ch <= 'z') {
                ch -= 32;
            }
            str1 = str1 + ch;
        }
        System.out.println("The converted string is - " + str1);
    }
}