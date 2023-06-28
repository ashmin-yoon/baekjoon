import java.io.*;
import java.util.*;

public class BOJ11725 {

    static final int MAX_SIZE = 100001;
    static List<Integer>[] adj = new List[MAX_SIZE];
    static int[] parent = new int[MAX_SIZE];
    static int N;
    public static void main(String[] args) throws IOException {
        // 트리의 루트는 1
        init();
        input();
        solution();

        StringBuilder sb = new StringBuilder();
        for (int i = 2; i <= N; i++) {
            sb.append(parent[i]).append("\n");
        }
        System.out.print(sb);
    }

    private static void init() {
        for (int i = 0; i < MAX_SIZE; i++) {
            adj[i] = new ArrayList();
            parent[i] = -1; // 부모 초기화
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            int v1 = Integer.parseInt(st.nextToken());
            int v2 = Integer.parseInt(st.nextToken());

            adj[v1].add(v2);
            adj[v2].add(v1);
        }
    }

    private static void solution() {
        Queue<Integer> q = new LinkedList<>();
        parent[1] = 0; // 1의 부모 설정
        q.add(1);

        while(!q.isEmpty()) {
            int vertex = q.remove();

            // 자식 탐색
            for (int child : adj[vertex]) {
                // 이미 부모 찾음(방문함)
                if (parent[child] != -1)
                    continue;

                q.add(child);
                parent[child] = vertex;
            }
        }
    }
}
