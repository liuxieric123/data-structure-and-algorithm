package stack;

import java.util.Stack;
public class isValidBrackets {

    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{') {
                stack.push(s.charAt(i));
            } else if (stack.isEmpty()) {
                return false;
            } else {
                if (s.charAt(i) == ')' && stack.peek() != '(') return false;
                if (s.charAt(i) == ']' && stack.peek() != '[') return false;
                if (s.charAt(i) == '}' && stack.peek() != '{') return false;
                stack.pop();
            }
        }
        return stack.isEmpty();
    }

    public static boolean isValidShort (String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '{') stack.push('}');
            else if (s.charAt(i) == '(') stack.push(')');
            else if (s.charAt(i) == '[') stack.push(']');
            else if (stack.isEmpty() || s.charAt(i) != stack.pop()) return false;
        }

        return stack.isEmpty();
    }

}
