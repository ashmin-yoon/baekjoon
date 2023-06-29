import java.io.*;
import java.util.StringTokenizer;

public class BOJ11404 {
    private static final int MAX_SIZE = 100 + 1;
    private static final int INF = 987654321;
    private static BufferedReader br;
    private static int N, M;
    private static int[][] distance = new int[MAX_SIZE][MAX_SIZE];
    private static StringBuilder sb = new StringBuilder();
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        StringTokenizer st;
        init();
        for (int k = 0; k < M; k++) {
            st = new StringTokenizer(br.readLine());
            int i = Integer.parseInt(st.nextToken());
            int j = Integer.parseInt(st.nextToken());

            // 노선이 하나가 아닐 수 있다.
            distance[i][j] = Math.min(distance[i][j], Integer.parseInt(st.nextToken()));
        }

        floydWarshall();
        createAnswer();
        System.out.print(sb);
        br.close();
    }

    private static void init() {
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                distance[i][j] = INF;
            }
            // 자기 자신 0
            distance[i][i] = 0;
        }
    }

    private static void floydWarshall() {
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    if (distance[i][k] == INF || distance[k][j] == INF)
                        continue;
                    distance[i][j] = Math.min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
    }

    private static void createAnswer() {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (distance[i][j] == INF)
                    sb.append(0).append(' ');
                else
                    sb.append(distance[i][j]).append(' ');
            }
            sb.append('\n');
        }
    }
}
