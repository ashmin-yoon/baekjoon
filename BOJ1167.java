import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ1167 {
    private static int V;
    private static final int MAX_SIZE = 100001;
    private static Node[] node = new Node[MAX_SIZE];
    private static int diameter = 0;

    static class Node {
        int number;
        boolean visited;
        List<Node> children = new ArrayList<>();
        List<Integer> distList = new ArrayList<>();
        public Node(int number) {
            this.number = number;
            this.visited = false;
        }
    }

    public static void main(String[] args) throws IOException {
        init();
        input();
        solution(node[1]);
        System.out.print(diameter);
    }

    private static void init() {
        for (int i = 0; i < MAX_SIZE; i++) {
            node[i] = new Node(i);
        }
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        V = Integer.parseInt(br.readLine());

        int vertex, child, dist;
        StringTokenizer st;
        for (int i = 0; i < V; i++) {
            st = new StringTokenizer(br.readLine());
            vertex = Integer.parseInt(st.nextToken());

            while (true) {
                child = Integer.parseInt(st.nextToken());
                // 중단 조건
                if (child == -1)
                    break;
                dist = Integer.parseInt(st.nextToken());

                node[vertex].distList.add(dist);
                node[vertex].children.add(node[child]);
            }
        }
    }

    private static int solution(Node start) {
        start.visited = true;
        if (start.children.isEmpty())
            return 0;


        // 1967과 로직이 약간 다르다.
        // 주어진 데이터 형식이 달라졌음
        int preMax = 0;
        for (int i = 0; i <start.children.size(); i++) {
            Node child = start.children.get(i);
            int dist = start.distList.get(i);

            // 이미 방문함
            if (child.visited)
                continue;

            int curr = dist + solution(child);

            // 자식들간 거리 합과 비교
            diameter = Math.max(diameter, preMax + curr);
            preMax = Math.max(preMax, curr); // 최대 길이 자식 갱신
        }

        // 가장 긴 자식 + 자신
        return preMax;
    }
}
