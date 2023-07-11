import java.io.*;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ1916 {
    private static int N, M;
    private static final int MAX_SIZE = 1001;
    private static final int INF = 1987654321;
    private static int[][] cost = new int[MAX_SIZE][MAX_SIZE];
    private static int start, end;

    public static void main(String[] args) throws IOException {
        init();
        input();
        System.out.print(solution());
    }

    static class Info implements Comparable<Info> {
        int end;
        int cost;
        public Info(int end, int cost) {
            this.end = end;
            this.cost = cost;
        }

        @Override
        public int compareTo(Info info) {
            // PQ 오름차순 낮은 수치가 가장 앞
            return this.cost - info.cost;
        }
    }

    private static void init() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Arrays.fill(cost[i], INF);
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int e = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());

            cost[s][e] = Math.min(cost[s][e], c);
        }
        st = new StringTokenizer(br.readLine());
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());
    }

    private static int solution() {
        int[] dist = dijkstra(start);
        return dist[end];
    }

    private static int[] dijkstra(int start) {
        int[] dist = new int[N + 1];
        boolean[] visited = new boolean[N + 1];
        Arrays.fill(dist, INF);
        Arrays.fill(visited, false);

        dist[start] = 0;
        PriorityQueue<Info> pq = new PriorityQueue<>();

        pq.add(new Info(start, 0));

        while (!pq.isEmpty()) {
            Info info = pq.remove();

            if (visited[info.end])
                continue;
            visited[info.end] = true;
            System.out.println("info.end = " + info.end);

            for (int i = 1; i <= N; i++) {
                // 경로 없음 || 경로 없음(노선 없음)
                if (dist[info.end] == INF || cost[info.end][i] == INF)
                    continue;

                if (dist[i] > dist[info.end] + cost[info.end][i]) {
                    dist[i] = dist[info.end] + cost[info.end][i];
                    pq.add(new Info(i, dist[i]));
                }
            }
        }

        return dist;
    }
}
