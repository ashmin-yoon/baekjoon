import java.io.*;
import java.util.StringTokenizer;

public class BOJ20040 {
    private static int N, M, ans;
    private static final int MAX_SIZE = 500000;
    private static int [] parent = new int [MAX_SIZE];
    public static void main(String args[]) throws IOException {
        for (int i = 0; i < MAX_SIZE; i++) {
            parent[i] = i;
        }
        input();
        System.out.print(ans);
    }

    private static int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    private static void union(int x, int y) {
        int groupX = find(x);
        int groupY = find(y);

        parent[groupY] = groupX;
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        ans = 0;
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            if (ans == 0 && find(x) == find(y)) {
                ans = i + 1;
            }
            union(x, y);
        }
    }
}
