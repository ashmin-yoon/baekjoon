import java.io.*;
import java.util.*;

public class BOJ9465 {
    private static final int MAX_SIZE = 100000;
    private static BufferedReader br;
    private static int T, N;
    private static int[][] arr = new int[2][MAX_SIZE];
    private static int[][] dp = new int[2][MAX_SIZE];
    private static StringBuilder sb;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        sb = new StringBuilder();
        T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            input();
            solution();
        }

        System.out.print(sb);
        br.close();
    }

    private static void input() throws IOException {
        N = Integer.parseInt(br.readLine());

        for (int i = 0; i < 2; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                dp[i][j] = 0; // 초기화
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    private static void solution() {
        // 첫 열 설정
        dp[0][0] = arr[0][0];
        dp[1][0] = arr[1][0];

        // 두 번째 열
        dp[0][1] = arr[0][1] + dp[1][0];
        dp[1][1] = arr[1][1] + dp[0][0];

        // 현재 칸은 이전 열의 대각칸 + 자신값
        // 자신 칸 + (이전 열의 대각 칸, 이이전 열 중 큰 값) 중 가장 큰 값 선택
        for (int i = 2; i < N; i++) {
            dp[0][i] = arr[0][i] + Math.max(dp[1][i - 1], Math.max(dp[0][i - 2], dp[1][i - 2]));
            dp[1][i] = arr[1][i] + Math.max(dp[0][i - 1], Math.max(dp[0][i - 2], dp[1][i - 2]));
        }

        int ans = Math.max(dp[0][N - 1], dp[1][N - 1]);
        sb.append(ans).append('\n');
    }


}
