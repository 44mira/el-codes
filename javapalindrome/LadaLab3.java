/* Takes a string and checks if palindrome */

import java.util.Scanner;
import java.util.Stack;
import java.lang.StringBuilder;

class LadaLab3 {

    public static void main(String[] args) {

        /* Object construction */
        Scanner sc = new Scanner(System.in);
        Stack<Character> st = new Stack<Character>();
        StringBuilder sb = new StringBuilder();
        
        String rev_inp, inp = sc.nextLine();
        /* sets to lowercase, and then removes all special characters and whitespace */
        inp = inp.toLowerCase().replaceAll("[^A-Za-z0-9]|\\s+", "");            

        /* push and pop characters */
        for (char c : inp.toCharArray())
            st.push(c);
        while (!st.isEmpty())
            sb.append(st.pop());                /* StringBuilder object is used to construct reversed string */
        rev_inp = sb.toString();

        /* Ternary for equality check with reversed input */
        System.out.printf("The string is %s.\n", (inp.equals(rev_inp) ? "a palindrome" : "not a palindrome"));

        sc.close();
    }
}