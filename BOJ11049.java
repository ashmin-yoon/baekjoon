import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;

public class BOJ11049 {
    private static int N;
    private static final int MAX_SIZE = 501;
    private static int[] matrixRow = new int [MAX_SIZE];
    private static int[] matrixCol = new int [MAX_SIZE];
    private static int[][] cache = new int [MAX_SIZE][MAX_SIZE];

    public static void main(String args[]) throws IOException {
        init();
        input();
        solution();
    }

    private static void init() {
        for (int i = 0 ; i < MAX_SIZE; i++) {
            Arrays.fill(cache[i], -1);
            cache[i][i] = 0;
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            matrixRow[i] = Integer.parseInt(st.nextToken());
            matrixCol[i] = Integer.parseInt(st.nextToken());
        }

    }

    private static void solution() {
        int ans = -1;
        // 행렬 2개 곱 ~ 전체 곱
        for (int l = 2; l <= N; l++) {
            for (int i = 0; i < N - l + 1; i++) {
                int j = i + l - 1;
                for (int k = i; k < j; k++) {
                    //[i, k] * [k + 1, j]
                    // 계산 수 matrixRow[i] * matrixRow[k + 1] * matrixCol[j]
                    // 이전 계산된 값 cache
                    int preCalc = cache[i][k] + cache[k + 1][j];
                    int newCalc = matrixRow[i] * matrixRow[k + 1] * matrixCol[j];

                    if (cache[i][j] == -1 || cache[i][j] > preCalc + newCalc) {
                        cache[i][j] = preCalc + newCalc;
                    }
                }

            }
        }

        System.out.println(cache[0][N - 1]);
    }
}
