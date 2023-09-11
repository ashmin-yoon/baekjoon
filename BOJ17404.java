import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ17404 {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int N;
    private static final int MAX_SIZE = 1001, INF = 987654321;
    private static int[][] cost = new int [MAX_SIZE][3];
    private static int[][] sum = new int [MAX_SIZE][3];

    public static void main(String args[]) throws IOException {
        init();
        input();
        solution();
    }

    static int findSumValue(int start) {
        int _sum = INF;
        for (int i = 0; i < MAX_SIZE; i++)
            Arrays.fill(sum[i], INF);

        sum[1][start] = cost[1][start];

        // 두번째 라인 세팅
        for (int j = 0; j < 3; j++) {
            if (start != j) sum[2][j] = cost[2][j] + sum[1][start];
        }

        // 마지막 라인까지
        for (int i = 3; i <= N; i++) {
            for (int j = 0; j < 3; j++) {
                int preSum = INF;
                // 마지막 라인에서 시작 번호와 비교
                if (i == N && start == j)
                    continue;

                if (j != 0) preSum = Math.min(preSum, sum[i - 1][0]);
                if (j != 1) preSum = Math.min(preSum, sum[i - 1][1]);
                if (j != 2) preSum = Math.min(preSum, sum[i - 1][2]);
                sum[i][j] = cost[i][j] + preSum;
            }
        }

        // 결과 값 계산
        for (int i = 0; i < 3; i++)
            _sum = Math.min(sum[N][i], _sum);
        return _sum;
    }

    private static void solution() {
        int ans = INF;
        for (int i = 0; i < 3; i++) {
            ans = Math.min(ans, findSumValue(i));
        }
        System.out.println(ans);
    }


    private static void init() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Arrays.fill(cost[i], 0);
        }
    }
    private static void input() throws IOException {
        N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            cost[i][0] = Integer.parseInt(st.nextToken());
            cost[i][1] = Integer.parseInt(st.nextToken());
            cost[i][2] = Integer.parseInt(st.nextToken());
        }
    }
}
