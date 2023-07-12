import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ14938 {
    private static int N, M, R;
    private static final int MAX_SIZE = 101;
    private static final int INF = 1987654321;
    private static int[][] dist = new int [MAX_SIZE][MAX_SIZE];
    private static int[] item = new int[MAX_SIZE];
    private static int[] totalItem = new int[MAX_SIZE];
    public static void main(String[] args) throws IOException {

        init();
        input();
        System.out.println(solution());
    }

    private static void init() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0; // 자기 자신
        }
        Arrays.fill(totalItem, 0);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());

        // 각 지역별 아이템 수
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            item[i] = Integer.parseInt(st.nextToken());
        }

        // 경로
        for (int i = 0; i < R; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int length = Integer.parseInt(st.nextToken());

            // 길은 양방향
            dist[u][v] = Math.min(dist[u][v], length);
            dist[v][u] = Math.min(dist[v][u], length);
        }
    }

    private static int solution() {
        int ans = 0;
        floydWarshall();

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][j] <= M) {
                    totalItem[i] += item[j];
                }
            }

            ans = Math.max(ans, totalItem[i]);
        }

        return ans;
    }


    private static void floydWarshall() {
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (dist[i][k] == INF || dist[j][k] == INF)
                        continue;
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }



}

