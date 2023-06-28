import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ15663 {
    private static int N, M;
    private static int[] arr;
    private static int[] selected = new int[8];
    private static boolean[] visited = new boolean[8];
    private static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        // 선택 초기화
        Arrays.fill(selected, -1);
        Arrays.fill(visited, false);

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        // 데이터 입력
        st = new StringTokenizer(br.readLine());
        arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        // 데이터 정렬
        Arrays.sort(arr); // 기본 오름차순 정렬

        solution(0);

        System.out.print(sb);
        br.close();
    }

    private static void solution(int count) {
        // 한 줄 완성
        if (count == M) {
            for (int i = 0; i < M; i++) {
                sb.append(selected[i]).append(" ");
            }
            sb.append("\n");
            return;
        }


        for (int i = 0; i < N; i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            // 중복 검사 후 진행 (이전에 선택한 숫자와 현재 숫자 비교)
            // 엄청 오래 걸려 찾은 것은
            // 이전에 뒤쪽(오른쪽)에 selected 로 선택된 값이 남아 있어서 무시가 됨.
            // 따라서 재귀를 들어갈 때 다음 선택 비우기
            // 다른 방법은 함수 내부 변수를 두고 현재 바로 이전 선택 저장 후 비교
            if (selected[count] != arr[i]) {
                selected[count] = arr[i]; // 현재 값 선택
                if (count + 1 < M)
                    selected[count + 1] = -1;
                solution(count + 1);
            }
            visited[i] = false;
        }
    }
}
