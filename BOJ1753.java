import java.io.*;
import java.util.*;

public class BOJ1753 {
    static int MAX_SIZE = 20001;
    static int INF = 987654321;
    static Map<Integer, Integer>[] maps = new HashMap[MAX_SIZE];
    static int[] dist = new int[MAX_SIZE];
    static boolean[] visited = new boolean[MAX_SIZE];
    static int V, E, START;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        START = Integer.parseInt(br.readLine());

        init();

        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            // 기존 간선이 있으면 가장 작은 가중치로 변경
            if (maps[u].containsKey(v)) {
                if (maps[u].get(v) > w) {
                    maps[u].replace(v, w);
                }
            }
            else {
                maps[u].put(v, w);
            }
        }

        System.out.print(solution());
        br.close();
    }

    private static void init() {
        Arrays.fill(dist, INF);

        for (int i = 0; i <= V; i++) {
            maps[i] = new HashMap<>();

            visited[i] = false;
        }
    }

    // Dijkstra
    private static String solution() {
        PriorityQueue<Info> pq = new PriorityQueue<>();

        dist[START] = 0;
        pq.add(new Info(START, 0));

        while(!pq.isEmpty()) {
            int u = pq.peek().vertex;
            int w = pq.peek().weight;
            pq.remove();

            if (visited[u]) continue;
            // 방문 처리
            visited[u] = true;

            // u 에서 인접한 정점들
            Iterator<Integer> keys = maps[u].keySet().iterator();
            for (int v : maps[u].keySet()) {
                int weight = maps[u].get(v);

                // 짧은 거리로 갱신
                if (dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    pq.add(new Info(v, dist[v]));
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= V; i++) {
            if (dist[i] == INF) sb.append("INF");
            else sb.append(dist[i]);

            sb.append("\n");;
        }
        return sb.toString();
    }
}

class Info implements Comparable<Info> {
    int vertex;
    int weight;
    public Info(int vertex, int weight) {
        this.vertex = vertex;
        this.weight = weight;
    }

    @Override
    public int compareTo(Info info) {
        return this.weight - info.weight;
    }
}