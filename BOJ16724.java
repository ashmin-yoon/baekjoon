import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;


public class BOJ16724 {
    private static int N, M;
    private static final int MAX_SIZE = 1001;
    private static final int U = 0, D = 1, L = 2, R = 3;
    private static int[] dy = {-1, 1, 0, 0}; // U, D, L, R 순서
    private static int[] dx = {0, 0, -1, 1};
    private static boolean[] visited = new boolean[MAX_SIZE * MAX_SIZE];
    private static int [][] dir = new int [MAX_SIZE][MAX_SIZE];
    private static int[] parent = new int [MAX_SIZE * MAX_SIZE];

    public static void main(String args[]) throws IOException {
        init();
        input();
        solution();
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

    private static void init() {
        for (int i = 0; i < MAX_SIZE * MAX_SIZE; i++) {
            parent[i] = i;
        }

        Arrays.fill(visited, false);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                char ch = line.charAt(j);
                if (ch == 'U') dir[i][j] = U;
                else if(ch == 'D') dir[i][j] = D;
                else if(ch == 'L') dir[i][j] = L;
                else if(ch == 'R') dir[i][j] = R;
            }
        }
    }

    private static void move(int y, int x) {
        int ny = y + dy[dir[y][x]];
        int nx = x + dx[dir[y][x]];

        int curr = y * M + x;
        int next = ny * M + nx;

        while (find(curr) != find(next)) {
            union(curr, next);

            y = ny;
            x = nx;
            ny = y + dy[dir[y][x]];
            nx = x + dx[dir[y][x]];
            curr = y * M + x;
            next = ny * M + nx;
        }
    }
    private static void solution() {
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                move(i, j);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int currSet = find(i * M + j);
                if (!visited[currSet]) {
                    visited[currSet] = true;
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }
}
