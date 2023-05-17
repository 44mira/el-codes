/* 
 * Legolas Tyrael B. Lada  1-BSCS
 * 2022-04734
 * Convert an infix expression to postfix using Stack  
 */

import java.util.Scanner;
import java.util.Stack;

public class ladalab4 {

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);

        System.out.println("Input infix expression: ");
        String[] expr = sc.nextLine().split("");
        
        System.out.println("The resulting postfix expression is : " + infixToPostfix(expr));

        sc.close();
    }

    /* converts infix notation to postfix */
    public static String infixToPostfix(String[] expr){
        Stack<String> st = new Stack<>();
        String postfix = "";

        for (String term : expr){
            if (term.equals(" ")) continue;
            if (isNumeric(term))                                            /* push onto result if numeric */
                postfix += term + " ";
            else if (term.equals("("))                                      /* push onto stack if grouping */
                st.push(term);
            else if (term.equals(")")){                                     /* pop stack into result if closing parenthesis */
                while (!st.empty() && !st.peek().equals("(")) 
                    postfix += st.pop() + " ";
                st.pop();                                                   /* remove opening parenthesis */
            } else {                                                        /* compare precedence */
                while (!st.empty() && preced(term) <= preced(st.peek())) 
                    postfix += st.pop() + " ";
                st.push(term);
            }
        }

        /* pop remaining stack contents */
        while (!st.empty())
            postfix += st.pop() + " ";

        return postfix.trim();
    }

    /* function for checking precedence */
    public static int preced(String op){
        final int LOW = 1;
        final int HIGH = 2;
        final int NONE = 0;

        switch (op) {
            case "+":
            case "-":
                return LOW;
            case "*":
            case "/":
                return HIGH;
            default : 
                return NONE;
        }
    }

    /* checks if String is numeric */
    public static boolean isNumeric(String c){
        try {
            Integer.parseInt(c);
            return true;
        } catch (NumberFormatException e){
            return false;
        }
    }
}