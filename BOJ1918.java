import java.io.*;
import java.util.Stack;

public class BOJ1918 {
    private static BufferedReader br;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));

        String prefix = br.readLine();
        String postfix = prefixToPostfix(prefix);

        System.out.print(postfix);
    }

    private static String prefixToPostfix(String prefix) {
        StringBuilder sb = new StringBuilder();
        Stack<Character> stack = new Stack<Character>();

        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix.charAt(i);

            // 알파벳
            if (Character.isAlphabetic(ch)) {
                sb.append(ch);
                continue;
            }

            if (isBracket(ch)) {
                if (ch == ')') {
                    while(!stack.empty() && stack.peek() != '(') {
                        sb.append(stack.pop());
                    }
                    stack.pop(); // 열린 괄호 제거
                }
                else { // '('
                    stack.push(ch);
                }
                continue;
            }

            // 연산자
            int priority = getPriority(ch);

            // 스택 안에 우선순위가 같거나 보다 큰 것이 있을 경우 pop
            while(!stack.empty() && getPriority(stack.peek()) >= priority) {
                sb.append(stack.pop());
            }
            // 추가
            stack.push(ch);
        }

        // 다 끝나고 남은 내용 추가
        while(!stack.empty()) {
            sb.append(stack.pop());
        }

        return sb.toString();
    }

    private static int getPriority(char ch) {
        switch(ch) {
            case '+': case '-':
                return 0;
            case '*': case '/':
                return 1;
        }
        return -1;
    }

    private static boolean isBracket(char ch) {
        if (ch == '(' || ch == ')')
            return true;
        return false;
    }
}
