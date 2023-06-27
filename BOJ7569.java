import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ7569 {
    private static int MAX_SIZE = 100;
    private static int M, N, H, TOTAL_TOMATO = 0; // 가로, 세로, 높이
    private static int[][][] tomato = new int[MAX_SIZE][MAX_SIZE][MAX_SIZE];
    private static Queue<Pos> q = new LinkedList<>();
    private static int[] dy = {-1, 0, 1, 0, 0, 0}; // 상, 우, 하, 좌, 위, 아래
    private static int[] dx = {0, 1, 0, -1, 0, 0};
    private static int[] dz = {0, 0, 0, 0, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        // tomato[세로][가로][높이]
        for (int k = 0; k < H; k++) {
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < M; j++) {
                    tomato[i][j][k] = Integer.parseInt(st.nextToken());
                    if (tomato[i][j][k] == 1) {
                        q.add(new Pos(i, j, k));
                    }

                    // 총 토마토 수
                    if (tomato[i][j][k] != -1)
                        TOTAL_TOMATO++;
                }
            }
        }

        System.out.print(solution());

    }

    private static int solution() {
        int day = 0;
        int tomatoCnt = q.size();


        while(!q.isEmpty()) {
            int daySize = q.size();

            // 전부 익었을 경우
            if (tomatoCnt == TOTAL_TOMATO)
                return day;

            while(daySize-- > 0) {
                int y = q.peek().y;
                int x = q.peek().x;
                int z = q.peek().z;
                q.poll();

                // 인접 토마토 확인
                for (int i = 0; i < 6; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    int nz = z + dz[i];

                    if (outOfRange(ny, nx, nz)) continue;
                    // 이미 익은 토마토 or 비어있음
                    if (tomato[ny][nx][nz] == -1 || tomato[ny][nx][nz] == 1) continue;

                    q.add(new Pos(ny, nx, nz));
                    tomato[ny][nx][nz] = 1;
                    tomatoCnt++;
                }

            }

            day++;
        }

        return -1;
    }

    private static boolean outOfRange(int y, int x, int z) {
        if (y < 0 || y >= N) return true;
        if (x < 0 || x >= M) return true;
        if (z < 0 || z >= H) return true;
        return false;
    }

}

class Pos {
    int y;
    int x;
    int z;
    public Pos(int y, int x, int z) {
        this.y = y;
        this.x = x;
        this.z = z;
    }

}
