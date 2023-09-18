import java.io.*;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.Arrays;

public class BOJ20303 {
    private static int N, M, K;
    private static final int MAX_SIZE = 30001;
    private static final int CACHE_SIZE = 3001;
    private static long ans;
    private static long [] candy = new long [MAX_SIZE];
    private static int[] parent = new int [MAX_SIZE];
    private static int[] groupSize = new int [MAX_SIZE];
    private static long [] groupCandy = new long [MAX_SIZE];
    private static ArrayList<Integer> groups = new ArrayList<>();
    private static boolean[] visited = new boolean [MAX_SIZE];
    private static long [] cache = new long [CACHE_SIZE];

    public static void main(String args[]) throws IOException {
        init();
        input();
        solution();
    }


    private static void solution() {
        ans = 0;

        // 그룹 추출
        Arrays.fill(visited, false);
        for (int i = 1; i <= N; i++) {
            int group = find(i);
            if (visited[group]) continue;

            visited[group] = true;
            groups.add(group);
        }


        ans = travel();
        System.out.println(ans);

    }



    private static long travel() {
        // Bottom up dp
        // 2차원 배열이 아닌 1차원으로 하기 위해
        // weight 뒤에서 앞으로 진행
        for (int i = 0; i < groups.size(); i++) {
            int group = groups.get(i);
            for (int w = K - 1; w >= 0; w--) {
                // 선태 X == 그 대로 cache[w]
                // 선택 O == cache[w + groupSize[group]] + groupCandy[group]
                if (w >= groupSize[group])
                    cache[w] = Math.max(cache[w], cache[w - groupSize[group]] + groupCandy[group]);
            }
        }

        return cache[K - 1];
   }

    private static void init() {
        Arrays.fill(groupSize, 1);
        Arrays.fill(cache, 0);
        for (int i = 0; i < MAX_SIZE; i++) {
            parent[i] = i;
        }
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
        groupSize[setX] += groupSize[setY];
        groupCandy[setX] += groupCandy[setY];
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= N; i++) {
            candy[i] = Long.parseLong(st.nextToken());
            groupCandy[i] = candy[i];
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            union(a, b);
        }

        br.close();
    }
}
