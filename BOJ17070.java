import java.io.*;
import java.util.StringTokenizer;
public class BOJ17070 {
    private static int N;
    private static int[][] board = new int[18][18];
    private static int[][][] cnt = new int[18][18][3]; // 가로, 세로, 대각선
    private static final int WALL = 1;
    private static final int HORIZON = 0;
    private static final int VERTICAL = 1;
    private static final int DIAGONAL = 2;


    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solution());
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        // 0행, N + 1행 벽
        // 0열, N + 1열 벽
        for (int i = 0; i <= N + 1; i++) {
            board[i][0] = WALL;
            board[i][N + 1] = WALL;

            board[i][0] = WALL;
            board[i][N + 1] = WALL;
        }

        // 초기 위치 설정
        if (board[1][1] != WALL && board[1][2] != WALL) {
            cnt[1][2][HORIZON] = 1;
        }

    }

    private static void moveNext(int y, int x, int dir) {
        if (dir == HORIZON) {
            moveRight(y, x, dir);
            moveDiagonal(y, x, dir);
        } else if (dir == DIAGONAL) {
            moveRight(y, x, dir);
            moveDiagonal(y, x, dir);
            moveDown(y, x, dir);
        } else if (dir == VERTICAL) {
            moveDiagonal(y, x, dir);
            moveDown(y, x, dir);
        }
    }

    // 대각 이동
    private static void moveDiagonal(int y, int x, int dir) {
        if (board[y][x + 1] == WALL || board[y + 1][x + 1] == WALL
                || board[y + 1][x] == WALL)
            return;
        cnt[y + 1][x + 1][DIAGONAL] += cnt[y][x][dir];
    }

    private static void moveRight(int y, int x, int dir) {
        if (board[y][x + 1] == WALL)
            return;

        cnt[y][x + 1][HORIZON] += cnt[y][x][dir];
    }

    private static void moveDown(int y, int x, int dir) {
        if (board[y + 1][x] == WALL)
            return;

        cnt[y + 1][x][VERTICAL] += cnt[y][x][dir];
    }

    private static int solution() {

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int dir = 0; dir < 3; dir++) {
                    moveNext(i, j, dir);
                }
            }
        }
        return cnt[N][N][HORIZON] + cnt[N][N][VERTICAL] + cnt[N][N][DIAGONAL];
    }

    private static void print() {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                System.out.print(cnt[i][j][HORIZON] + cnt[i][j][VERTICAL] + cnt[i][j][DIAGONAL] + " ");
            }
            System.out.println();
        }
    }

}
