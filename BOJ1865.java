import java.io.*;
import java.util.*;

public class BOJ1865 {
    private static BufferedReader br;
    private static int N, M, W;

    private static final int MAX_SIZE = 501;
    private static final int INF = 987654321;
    private static int[][] dist = new int[MAX_SIZE][MAX_SIZE];


    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            initDist();
            input();
            System.out.println(solution());
        }
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken()); // 지점 수
        M = Integer.parseInt(st.nextToken()); // 도로 수
        W = Integer.parseInt(st.nextToken()); // 웜홀 수

        int S, E, T;
        // 도로 정보
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            S = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());
            T = Integer.parseInt(st.nextToken());

            // 도로는 가장 짧은 시간 선택
            // 양방향
            dist[S][E] = Math.min(dist[S][E], T);
            dist[E][S] = Math.min(dist[E][S], T);
        }

        // 웜홀 정보
        for (int i = 0; i < W; i++) {
            st = new StringTokenizer(br.readLine());
            S = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());
            T = Integer.parseInt(st.nextToken());

            // 단 방향
            dist[S][E] = Math.min(dist[S][E], -T);
        }
    }

    public static void initDist() {
        for (int i = 0; i < MAX_SIZE; i++) {
            for (int j = 0; j < MAX_SIZE; j++) {
                dist[i][j] = INF;
            }
            dist[i][i] = 0;
        }
    }

    private static String solution() {

        // Floyd Warshall
        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    // 중간 경로 없음
                    if (dist[i][k] == INF || dist[k][j] == INF)
                        continue;
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
                if (dist[i][i] < 0)
                    return "YES";
            }
        }

        for (int start = 1; start <= N; start++) {
            if (dist[start][start] < 0) {
                return "YES";
            }
        }
        return "NO";
    }

}
