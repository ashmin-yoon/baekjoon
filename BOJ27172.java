import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ27172 {
    static int N;
    private static final int MAX_SIZE = 100001;
    private static final int MAX_SCORE = 1000001;
    static int[] player = new int[MAX_SIZE];
    static int[] score = new int [MAX_SIZE];
    static int[] numbers = new int [MAX_SCORE];
    public static void main(String args[]) throws IOException {
        Arrays.fill(numbers, -1);
        input();
        solution();
    }

    private static void solution() {
        StringBuilder sb = new StringBuilder();

        int value;
        for (int i = 1; i <= N; i++) {
            value = player[i];
            for (int j = value * 2; j < MAX_SCORE; j += value) {
                // 존재하지 않음
                if (numbers[j] == -1)
                    continue;
                // 배수 존재
                if (j % value == 0) {
                    score[i]++;
                    score[numbers[j]]--;
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            sb.append(score[i]).append(' ');
        }
        System.out.println(sb);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 1; i <= N; i++) {
            player[i] = Integer.parseInt(st.nextToken());
            numbers[player[i]] = i; // [카드]를 들고 있는 플레이어 번호
            score[i] = 0;
        }
    }
}
