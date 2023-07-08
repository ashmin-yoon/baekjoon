import java.io.*;
import java.util.Arrays;

public class BOJ2448 {
    private static final int MAX_N = 3 * 1024;
    static char[][] board = new char [MAX_N][MAX_N * 2 - 1];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());

        for (char[] line : board) {
            Arrays.fill(line, ' ');
        }

        solution(0, 0, N);
        for (int i = 0; i < N; i++) {
            bw.write(board[i], 0, 2 * N - 1);
            bw.write('\n');
        }
        bw.flush();
        bw.close();
        br.close();
    }

    // 밑 변의 길이는 n * 2 - 1
    public static void solution(int y, int x, int n) {
        //System.out.println("y, x, n = (" + y + ", " + x + ", " + n + ")");
        // 최소 크기
        if (n == 3) {
            board[y][x + 2] = '*';
            board[y + 1][x + 1] = board[y + 1][x + 3] = '*';
            board[y + 2][x] = '*';
            board[y + 2][x + 1] = '*';
            board[y + 2][x + 2] = '*';
            board[y + 2][x + 3] = '*';
            board[y + 2][x + 4] = '*';
            return;
        }

        // 정사각형 단위로 진행
        solution(y, x + n / 2, n / 2); // 위
        solution(y + n / 2, x, n / 2); // 좌하
        solution(y + n / 2, x + n, n / 2); // 우하
    }
}
