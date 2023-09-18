import java.io.*;
import java.util.StringTokenizer;
import java.util.PriorityQueue;
import java.util.Arrays;

public class BOJ1197 {
    private static int V, E;
    private static PriorityQueue<Edge> pq = new PriorityQueue<>();
    private static final int MAX_SIZE = 10001;
    private static int[] parent = new int[MAX_SIZE];
    static class Edge implements Comparable<Edge> {
        int u, v, cost;
        public Edge() { }
        public Edge(int u, int v, int cost) {
            this.u = u;
            this.v = v;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge b) {
            return this.cost - b.cost;
        }
    }
    public static void main(String args[]) throws IOException {

        input();
        solution();
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        int u, v, cost;
        for (int i = 0; i < E; i++) {
            st = new StringTokenizer(br.readLine());
            u = Integer.parseInt(st.nextToken());
            v = Integer.parseInt(st.nextToken());
            cost = Integer.parseInt(st.nextToken());

            pq.add(new Edge(u, v, cost));
        }

    }

    private static void solution() {
        System.out.println(kruskal());
    }

    private static int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    private static void union(int x, int y) {
        int setX = find(x);
        int setY = find(y);

        if (setX == setY)
            return;
        parent[setY] = setX;
    }
    private static int kruskal() {
        for (int i = 1; i <= V; i++) {
            parent[i] = i;
        }

        int mstWeight = 0;
        int edgeCount = 0;

        if (!pq.isEmpty()) {
            Edge e = pq.poll();
            union(e.u, e.v);
            mstWeight = e.cost;
            edgeCount = 1;
        }

        while (!pq.isEmpty()) {
            Edge e = pq.poll();
            if (edgeCount == V - 1) {
                pq.clear();
                break;
            }

            // 사이클
            if (find(e.u) == find(e.v))
                continue;

            union(e.u, e.v);
            mstWeight += e.cost;
        }
        return mstWeight;
    }
}
