import java.io.*;

class Main {
    public static int MAX_SIZE = 101;
    static Long[] arr = new Long[MAX_SIZE];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        // 초기값
        arr[0] = 0L;
        arr[1] = arr[2] = 1L;

        // 계산
        for (int i = 3; i < MAX_SIZE; i++) {
            arr[i] = arr[i - 2] + arr[i - 3];
        }

        // 출력할 문자열 생성기
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            sb.append(arr[n]).append("\n");
        }

        System.out.print(sb.toString());
    }
}
