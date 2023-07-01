import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ1967 {

    private static final int MAX_SIZE = 10001;
    private static Node[] node = new Node[MAX_SIZE];
    private static int N;
    private static int diameter = 0; // 지름

    static class Node {
        int number;
        int weight;
        List<Node> children = new ArrayList<>();
        public Node(int number, int weight) {
            this.number = number;
            this.weight = weight;
        }
    }

    public static void main(String[] args) throws IOException {
        init();
        input();
        solution(1);
        System.out.print(diameter);
    }

    private static void init() {
        for (int i = 0; i < MAX_SIZE; i++) {
            node[i] = new Node(i, 0);
        }
        node[1].weight = 0;
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        int parent, child, weight;
        for (int i = 0; i < N - 1; i++) {
            st = new StringTokenizer(br.readLine());
            parent = Integer.parseInt(st.nextToken());
            child = Integer.parseInt(st.nextToken());
            weight = Integer.parseInt(st.nextToken());

            // 자식의 가중치
            node[child].weight = weight;

            // 자식 설정
            node[parent].children.add(node[child]);
        }
    }

    private static int solution(int start) {
        //System.out.println("start = " + start);
        int weight = node[start].weight;

        // 자식 없음
        if (node[start].children.isEmpty()) {
            return weight;
        }

        int preMax = 0;
        for (Node child : node[start].children) {
            int curr = solution(child.number);

            // 아래 라인 합이 가장 길 경우
            diameter = Math.max(diameter, preMax + curr);
            // 이전 max 값 갱신
            preMax = Math.max(preMax, curr);
        }

        // 자신 + 자식 중 가장 긴 라인
        return weight + preMax;
    }


}
