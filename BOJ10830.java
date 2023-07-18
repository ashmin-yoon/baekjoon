import java.io.*;
import java.util.StringTokenizer;

public class BOJ10830 {
    private static int N;
    private static long B;
    private static final int MAX_SIZE = 5, MOD = 1000;
    private static int[][] arr = new int[MAX_SIZE][MAX_SIZE];

    public static void main(String[] args) throws IOException {
        input();
        int[][] ans = solution(arr, B);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                // 주의 마지막에도 % MOD 필요 -> b 1이고 원소가 1000인 경우 0 출력되어야 함
                sb.append(ans[i][j] % MOD).append(' ');
            }
            sb.append('\n');
        }
        System.out.println(sb);
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        B = Long.parseLong(st.nextToken());

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    static int[][] solution(int a[][], long b) {
        if (b == 1l) {
            return a;
        }

        int[][] a1 = solution(a, b / 2);
        int[][] a2 = a1;

        // 지수 홀수
        if (b % 2l == 1l)
            a2 = matMul(a1, a); // A^(b/2) * A

        return matMul(a1, a2);
    }

    static int[][] matMul(int m1[][], int m2[][]) {
        int result[][] = new int[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i][j] = 0;
                for (int k = 0; k < N; k++) {
                    result[i][j] += m1[i][k] * m2[k][j];
                    result[i][j] %= MOD;
                }
            }
        }
        return result;
    }

}
