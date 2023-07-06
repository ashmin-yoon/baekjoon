import java.io.*;
import java.util.*;

public class BOJ1865 {
    private static BufferedReader br;
    private static int N, M, W;

    private static final int MAX_SIZE = 501;
    private static final int INF = 987654321;
    private static List<Edge> edges = new ArrayList<>();
    private static int[] dist;
    private static boolean[] checked;
    static class Edge {
        int u;
        int v;
        int weight;
        public Edge(int u, int v, int weight) {
            this.u = u;
            this.v = v;
            this.weight = weight;
        }
    }


    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            initEdges();
            input();
            sb.append(solution()).append('\n');
        }
        System.out.println(sb);
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
            edges.add(new Edge(S, E, T));
            edges.add(new Edge(E, S, T));
        }

        // 웜홀 정보
        for (int i = 0; i < W; i++) {
            st = new StringTokenizer(br.readLine());
            S = Integer.parseInt(st.nextToken());
            E = Integer.parseInt(st.nextToken());
            T = Integer.parseInt(st.nextToken());

            // 단 방향
            edges.add(new Edge(S, E, -T));
        }
    }

    private static void initEdges() {
        edges.clear();
    }

    private static String solution() {
        dist = new int[N + 1];
        checked = new boolean[N + 1];
        Arrays.fill(dist, INF);
        Arrays.fill(checked, false);

        for (int i = 1; i <= N; i++) {
            if (bellmanFord(i))
                return "YES";
        }
        return "NO";
    }

    // 벨만-포드 알고리즘 활용
    // return true = 음의 사이클 존재, false = 음의 사이클 없음
    private static boolean bellmanFord(int start) {
        if (checked[start])
            return false;

        // 시작 지점 거리 초기화
        dist[start] = 0;

        // V - 1 번 반복
        for (int i = 0; i < N - 1; i++) {
            // E edge 전체 반복
            for (Edge edge : edges) {
                int u = edge.u;
                int v = edge.v;
                int time = edge.weight;

                // 경로 없음
                if (dist[u] == INF)
                    continue;

                // 현재까지 구한 v 까지 경로
                // u 까지의 경로 + u->v 경로  비교
                if (dist[v] > dist[u] + time) {
                    dist[v] = dist[u] + time;
                    checked[v] = true;
                }
            }
        }

        // 음수 사이클 판별
        for (Edge edge : edges) {
            if (dist[edge.u] == INF)
                continue;
            if (dist[edge.v] > dist[edge.u] + edge.weight)
                return true;
        }

        return false;
    }


}
