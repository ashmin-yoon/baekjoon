import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

// 시간 초과의 원인은 L, R 연산의 String 때문인 것 같다.

public class BOJ9019 {
    private static int MAX_SIZE = 10000;
    private static boolean visited[] = new boolean[MAX_SIZE];
    private static char op[] = new char[MAX_SIZE];
    private static int pre[] = new int[MAX_SIZE];
    private static Queue<Integer> queue = new LinkedList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        while(T-- > 0) {
            init();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            // 결과 문자열 추가
            sb.append(solution(start, end)).append("\n");
        }

        bw.write(sb.toString());
        //bw.flush();
        br.close();
        bw.close();
    }

    static void init() {
        queue.clear();

        for (int i = 0; i < MAX_SIZE; i++) {
            visited[i] = false;
            op[i] = ' ';
            pre[i] = -1;
        }
    }

    static String solution(int source, int destination) {
        String ans = "";
        queue.add(source);
        visited[source] = true;

        int value = -1;
        while(!queue.isEmpty()) {
            value = queue.remove().intValue();

            if (value == destination) {
                break;
            }

            int result;

            // D
            if (!visited[(result = opD(value))]) {
                queue.add(result);
                pre[result] = value;
                op[result] = 'D';
                visited[result] = true;
            }

            // S
            if (!visited[(result = opS(value))]) {
                queue.add(result);
                pre[result] = value;
                op[result] = 'S';
                visited[result] = true;
            }

            // L
            if (!visited[(result = opL(value))]) {
                queue.add(result);
                pre[result] = value;
                op[result] = 'L';
                visited[result] = true;
            }

            // R
            if (!visited[(result = opR(value))]) {
                queue.add(result);
                pre[result] = value;
                op[result] = 'R';
                visited[result] = true;
            }
        }


        // 경로 추적
        StringBuilder sb = new StringBuilder();
        while(pre[value] != -1) {
            sb.append(op[value]);
            value = pre[value];
        }

        // 뒤집기
        ans = sb.reverse().toString();
        return ans;
    }

    static int opD(int value) {
        return (value * 2) % MAX_SIZE;
    }

    static int opS(int value) {
        return (value + MAX_SIZE - 1) % MAX_SIZE;
    }

    static int opL(int value) {
        // 앞에 0으로 패딩
//        String paddingZero = String.format("%04d", value);
//        String leftString = paddingZero.substring(1, 4) + paddingZero.charAt(0);
//        return Integer.parseInt(leftString);
        return (value % 1000) * 10 + value / 1000;
    }

    static int opR(int value) {
//        String paddingZero = String.format("%04d", value);
//        String rightString = paddingZero.charAt(3) + paddingZero.substring(0, 3);
//        return Integer.parseInt(rightString);
        return (value / 10) + value % 10 * 1000;
    }

}
