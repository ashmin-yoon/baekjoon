import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ2096 {
    private static final int MAX_SIZE = 100001;
    private static final int INF = 1987654321;
    private static int[][] arr = new int[MAX_SIZE][3];
    private static int[][] minArr = new int[MAX_SIZE][3];
    private static int[][] maxArr = new int[MAX_SIZE][3];
    private static int N;

    public static void main(String[] args) throws IOException {
        init();
        input();
        solution();
    }

    private static void init() {
        // initial value
        Arrays.fill(arr[0], 0);
        Arrays.fill(minArr[0], 0);
        Arrays.fill(maxArr[0], 0);

        for (int i = 1; i < MAX_SIZE; i++) {
            Arrays.fill(arr[i], -1);
            Arrays.fill(minArr[i], INF);
            Arrays.fill(maxArr[i], -INF);
        }
    }
    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());


        StringTokenizer st;
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
            arr[i][2] = Integer.parseInt(st.nextToken());
        }
    }

    private static void solution() {
        int minValue = INF;
        int maxValue = -INF;

        for (int i = 1; i <= N; i++) {
            minArr[i][0] = arr[i][0] + Math.min(minArr[i - 1][0], minArr[i - 1][1]);
            maxArr[i][0] = arr[i][0] + Math.max(maxArr[i - 1][0], maxArr[i - 1][1]);

            minArr[i][1] = arr[i][1] + Math.min(minArr[i-1][1], Math.min(minArr[i-1][0], minArr[i-1][2]));
            maxArr[i][1] = arr[i][1] + Math.max(maxArr[i-1][1], Math.max(maxArr[i-1][0], maxArr[i-1][2]));

            minArr[i][2] = arr[i][2] + Math.min(minArr[i - 1][1], minArr[i - 1][2]);
            maxArr[i][2] = arr[i][2] + Math.max(maxArr[i - 1][1], maxArr[i - 1][2]);
        }
        minValue = Math.min(minArr[N][0], Math.min(minArr[N][1], minArr[N][2]));
        maxValue = Math.max(maxArr[N][0], Math.max(maxArr[N][1], maxArr[N][2]));

        System.out.println(maxValue + " " + minValue);
    }
}
