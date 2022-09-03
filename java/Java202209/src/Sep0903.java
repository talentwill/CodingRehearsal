import java.util.Stack;

public class Sep0903 {
}

class Solution36 {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String token: tokens) {
            switch (token) {
                case "+":
                case "-":
                case "*":
                case "/":
                    int num1 = stack.pop();
                    int num2 = stack.pop();
                    stack.push(calculate(num2, num1, token));
                    break;
                default:
                    stack.push(Integer.parseInt(token));
            }
        }
        return stack.pop();
    }

    private int calculate(int num1, int num2, String operator) {
        switch (operator) {
            case "+":
                return num1 + num2;
            case "-":
                return num1 - num2;
            case "*":
                return num1 * num2;
            case "/":
                return num1 / num2;
            default:
                return 0;
        }
    }
}

class Solution37 {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();
        for (int as : asteroids) {
            // if top < abs(as) every time, pop it all the way
            while (!stack.empty() && stack.peek() > 0 && stack.peek() < -as) {
                stack.pop();
            }
            if (!stack.empty() && as < 0 && stack.peek() == -as) {
                stack.pop();
            } else if (as > 0 || stack.empty() || stack.peek() < 0) {
                stack.push(as);
            }
        }
        return stack.stream().mapToInt(i ->i).toArray();
    }

    public static void main(String[] args) {
        int[] a1 = new int[] {10,2,-5};
        new Solution37().asteroidCollision(a1);
    }
}