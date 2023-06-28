import java.io.*;
import java.util.StringTokenizer;

public class BOJ11660 {
    private static int N, M;
    private static final int MAX_SIZE = 1024 + 1;
    private static int[][] matrix = new int[MAX_SIZE][MAX_SIZE];
    private static int[][] sum = new int[MAX_SIZE][MAX_SIZE];

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        input();

        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < M; i++) {
            Long ans = 0L;
            st = new StringTokenizer(br.readLine());
            int y1 = Integer.parseInt(st.nextToken());
            int x1 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());

            // 각 줄의 부분 합 더하기
            for (int y = y1; y <= y2; y++) {
                ans += sum[y][x2] - sum[y][x1 - 1];
            }
            sb.append(ans).append("\n");
        }

        System.out.print(sb);
        br.close();
    }

    private static void input() throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // N * N 크기
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                matrix[i][j] = Integer.parseInt(st.nextToken());
                sum[i][j] = sum[i][j - 1] + matrix[i][j];
            }
        }
    }
}
