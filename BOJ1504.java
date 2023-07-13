import java.io.*;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ1504 {
    private static int MAX_SIZE = 801;
    private static int[][] adj = new int[MAX_SIZE][MAX_SIZE];
    private static int N, E, inter1, inter2;
    private static final int INF = 1987654321;

    static class Info implements Comparable<Info> {
        int target;
        int cost;
        public Info(int target, int cost) {
            this.target = target;
            this.cost = cost;
        }

        @Override
        public int compareTo(Info info) {
            return this.cost - info.cost;
        }

    }
    public static void main(String[] args) throws IOException {
        init();
        input();
        System.out.println(solution());
    }

    // 초기화 값을 잘못 지정한 실수 함
    private static void init() {
        inter1 = inter2 = 0;
        for (int i = 0; i < MAX_SIZE; i++) {
            Arrays.fill(adj[i], INF);
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            // 무방향 = 양방향
            adj[u][v] = cost;
            adj[v][u] = cost;
        }

        // 반드시 거쳐야 할 정점
        st = new StringTokenizer(br.readLine());
        inter1 = Integer.parseInt(st.nextToken());
        inter2 = Integer.parseInt(st.nextToken());
    }

    private static int solution() {
        long ans = INF;
        // 중간에 경로가 없을 수 있음
        // 따라서 int는 표현 범위 벗어남

        // 1 -> N 까지의 최소 경로
        // 중간에 inter1, 2 무조건 거쳐야 함
        long[] distOfInter1 = dijkstra(inter1);
        long[] distOfInter2 = dijkstra(inter2);

        // 1 -> inter1 -> inter2 -> N
        long dist1 = distOfInter1[1] + distOfInter1[inter2] + distOfInter2[N];
        ans = Math.min(ans, dist1);

        // 1 -> inter2 -> inter1 -> N
        long dist2 = distOfInter2[1] + distOfInter2[inter1] + distOfInter1[N];
        ans = Math.min(ans, dist2);

//        System.out.println("dist1 = " + dist1);
//        System.out.println("dist2 = " + dist2);

        if (ans >= INF)
            return -1;
        return (int)ans;
    }

    private static long[] dijkstra(int start) {
        long[] dist = new long[N + 1];
        boolean[] visited = new boolean[N + 1];
        Arrays.fill(dist, INF);
        Arrays.fill(visited, false);

        dist[start] = 0;

        PriorityQueue<Info> pq = new PriorityQueue<>();
        pq.add(new Info(start, 0));

        while (!pq.isEmpty()) {
           int u = pq.remove().target;

            if (visited[u])
                continue;
            visited[u] = true;

            for (int i = 1; i <= N; i++) {
                if (dist[u] == INF || adj[u][i] == INF)
                    continue;

                if (dist[i] > dist[u] + adj[u][i]) {
                    dist[i] = dist[u] + adj[u][i];
                    pq.add(new Info(i, (int)dist[i]));
                }
            }
        }

        return dist;
    }

}
