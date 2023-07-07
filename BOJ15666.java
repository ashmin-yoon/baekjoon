import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ15666 {

    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static int[] arr;
    private static int[] selected = new int[9];

    public static void main(String[] args) throws IOException {

        input();
        Arrays.sort(arr);
        solution(0, 0);
        System.out.println(sb);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        arr = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    private static void solution(int index, int count) {
        if (count == M) {
            // 정답 출력
            for (int i = 0; i < count; i++) {
                sb.append(selected[i]).append(' ');
            }
            sb.append('\n');
            return;
        }

        for (int i = index; i < N; i++) {
            // 이전에 선택한 적 없을 때
            if (selected[count] != arr[i]) {
                selected[count] = arr[i];
                selected[count + 1] = -1;
                solution(i, count + 1);
            }
        }
    }

}
