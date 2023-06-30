import java.io.*;
import java.util.StringTokenizer;

public class BOJ1629 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long A = Integer.parseInt(st.nextToken());
        long B = Integer.parseInt(st.nextToken());
        long C = Integer.parseInt(st.nextToken());

        // 최종 답은 A^B % C
        System.out.print(solution(A, B, C));
    }

    // 해당 문제의 경우 값의 범위 때문에 답안 참고함
    private static long solution(long A, long B, long C) {
        if (B == 1) {
            return A % C;
        }

        long dividedValue = solution(A, B / 2, C);
        long powDividedValue = dividedValue * dividedValue;
        if (B % 2 == 0) {
            // A^8 = A^4 * A^4 * A;
            return powDividedValue % C;
        }
        else {
            // A^7 = A^3 * A^3 * A;
            return (powDividedValue % C) * A % C;
        }
    }
}
