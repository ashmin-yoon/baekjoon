import java.io.*;
import java.util.*;

public class BOJ11779 {
    private static int N, M;
    private static int S, E, count;
    private static final int INF = 1987654321;
    private static final int MAX_SIZE = 1001;
    private static int[][] adj = new int[MAX_SIZE][MAX_SIZE];
    private static boolean[] visited = new boolean[MAX_SIZE];
    private static int[] path = new int[MAX_SIZE]; // path 는 이전 위치
    static class Info implements Comparable<Info> {
        int pre;
        int target;
        int cost;
        public Info(int target, int cost) {
            this.target = target;
            this.cost = cost;
        }

        public Info(int pre, int target, int cost) {
            this.pre = pre;
            this.target = target;
            this.cost = cost;
        }

        @Override
        public int compareTo(Info info) {
            return this.cost - info.cost;
        }
    }

    public static void main(String[] args) throws IOException {
        StringBuilder sb = new StringBuilder();
        init();
        input();
        sb.append(solution()).append('\n');
        List<Integer> pathList = generatePath(S, E);
        sb.append(pathList.size()).append('\n');

        for (int v : pathList) {
            sb.append(v).append(' ');
        }
        System.out.println(sb);
    }

    private static void init() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Arrays.fill(adj[i], INF);
            adj[i][i] = 0;
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int cost = Integer.parseInt(st.nextToken());

            adj[u][v] = Math.min(cost, adj[u][v]);
        }
        st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
    }

    private static int solution() {
        return dijkstra(S)[E];
    }

    private static int[] dijkstra(int start) {
        int[] cost = new int[N + 1];
        Arrays.fill(cost, INF);
        Arrays.fill(visited, false);
        Arrays.fill(path, 0);
        cost[start] = 0;

        PriorityQueue<Info> pq = new PriorityQueue<>();
        pq.add(new Info(0, start, 0));

        while (!pq.isEmpty()) {
            int pre = pq.peek().pre;
            int u = pq.remove().target;
            if (visited[u])
                continue;
            visited[u] = true;
            path[u] = pre; // u로 가기위한 이전 위치

            for (int v = 1; v <= N; v++) {
                if (adj[u][v] == INF)
                    continue;

                if (cost[v] > cost[u] + adj[u][v]) {
                    cost[v] = cost[u] + adj[u][v];
                    pq.add(new Info(u, v, cost[v]));
                }
            }
        }

        return cost;
    }

    private static List<Integer> generatePath(int start, int end) {
        List<Integer> reversedPath = new ArrayList<>();
        reversedPath.add(end);

        int pre = path[end];
        while (pre != 0) {
            reversedPath.add(pre);
            pre = path[pre];
        }

        // 역순으로 된 경로 정상으로 뒤집기
        Collections.reverse(reversedPath);
        return reversedPath;
    }
}
