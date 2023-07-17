import java.io.*;

public class BOJ9935 {
    private static final int MAX_SIZE = 1000000;
    private static char[] ch = new char[MAX_SIZE];
    private static int top;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String str = br.readLine();
        String bomb = br.readLine();

        solution(str, bomb);
        for (int i = 0 ; i <= top; i++) {
            bw.write(ch[i]);
        }

        if (top == -1)
            bw.write("FRULA");

        bw.flush();
        bw.close();
        br.close();
    }



    private static void solution(String str, String bomb) {
        top = -1;

        boolean isEqual = false;
        char lastBombCh = bomb.charAt(bomb.length() - 1);

        for (int i = 0; i < str.length(); i++) {
            // 스택 형식
            ch[++top] = str.charAt(i);

            // 확인 후 제거
            while ((top + 1) >= bomb.length() && ch[top] == lastBombCh ) {
                // 폭탄 검사
                isEqual = true;
                for (int j = 0; j < bomb.length(); j++) {
                    if (ch[top - j] != bomb.charAt(bomb.length() - 1 - j)) {
                        isEqual = false;
                        break;
                    }
                }

                // 제거 작업
                if (isEqual) {
                    top -= bomb.length();
                }
                else {
                    break; // while 벗어남
                }
            }
        }
    }

}
