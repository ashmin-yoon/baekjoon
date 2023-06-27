import java.io.*;
import java.util.Arrays;

public class BOJ5430 {
    static int[] arr;
    static int left, right;
    static boolean reverse;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        String cmd;
        int N;
        String strArr;
        while (T-- > 0) {
            init();
            // input
            cmd = br.readLine();
            N = Integer.parseInt(br.readLine());
            strArr = br.readLine();

            setArray(strArr);
            sb.append(solution(cmd)).append("\n");
        }

        System.out.print(sb.toString());
    }

    static void init() {
        left = 0;
        right = 0;
        reverse = false;
    }

    static void setArray(String str) {
        String[] strings = str.substring(1, str.length() - 1).split(",");

        // "" 공백 문자열이 들어있는 경우 예외 발생함 -> filter로 해결
        arr = Arrays.stream(strings)
                .filter(s -> !s.equals(""))
                .mapToInt(Integer::parseInt).toArray();
    }

    static String solution(String cmd) {
        int dCount = 0;
        // [left, right)
        left = 0; right = arr.length;
        for (int i = 0; i < cmd.length(); i++) {
            char ch = cmd.charAt(i);
            if (ch == 'D') {
                if (!reverse) left++; // 정방향
                else right--; // 역방향
                dCount++;
            } else if (ch == 'R') {
                reverse = !reverse;
            }

            // 중단 조건 검사
            if (dCount > arr.length) {
                return "error";
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append("[");
        if(reverse) {
            for (int i = right - 1; i >= left + 1; i--) {
                sb.append(arr[i]).append(",");
            }
            if (left < right)
                sb.append(arr[left]);
        }
        else {
            for (int i = left; i < right - 1; i++) {
                sb.append(arr[i]).append(",");
            }

            if (right > left)
                sb.append(arr[right - 1]);
        }
        sb.append("]");

        return sb.toString();
    }
}

