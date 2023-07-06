import java.io.*;
import java.util.*;

public class BOJ1238 {

    private static int N, M, X;

    private static final int MAX_SIZE = 1001;
    private static final int INF = 987654321;
    private static List<List<Edge>> adj = new ArrayList<>();

    static class Edge implements Comparable<Edge> {
        int u, v, time;

        public Edge(int u, int v, int time) {
            this.u = u;
            this.v = v;
            this.time = time;
        }

        // 오름차순 정렬
        @Override
        public int compareTo(Edge edge) {
            return this.time - edge.time;
        }
    }


    public static void main(String[] args) throws IOException {
        init();
        input();
        System.out.print(solution());
    }

    private static void init() {
        for (int i = 0; i <= MAX_SIZE; i++) {
            adj.add(new ArrayList<>());
        }
    }


    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int time = Integer.parseInt(st.nextToken());

            adj.get(u).add(new Edge(u, v, time));
        }
    }

    private static int solution() {

        int ans = -INF;

        // 목적지 ~ 각 지점까지의 시간
        int[] fromTo = dijkstra(X);

        // 각 지점에서 출발 ~ 목적지 X까지
        for (int i = 1; i <= N; i++) {
            ans = Math.max(ans, dijkstra(i)[X] + fromTo[i]);
        }

        return ans;
    }


    private static int[] dijkstra(int start) {
        int[] dist = new int[N + 1];
        boolean[] visited = new boolean[N + 1];
        Arrays.fill(dist, INF);
        Arrays.fill(visited, false);

        // 자신
        dist[start] = 0;

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(0, start, 0));

        while (!pq.isEmpty()) {
            // u -> v, time
            int v = pq.remove().v;

            if (visited[v])
                continue;
            visited[v] = true; // v 방문

            // v 인접 간선
            for (Edge edge : adj.get(v)) {
                // u(중간 지점) 까지 경로 없음
                if (dist[edge.u] == INF)
                    continue;

                if (dist[edge.v] > dist[edge.u] + edge.time) {
                    dist[edge.v] = dist[edge.u] + edge.time;
                    pq.add(new Edge(start, edge.v, dist[edge.v])); // 간선 추가(정점 추가용)
                }
            }

        }

        return dist;
    }

}
