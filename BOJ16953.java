import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ16953 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        Queue<Integer> q = new LinkedList<>();
        q.add(A);
        boolean found = false;
        int ans = -1;
        int cnt = 1;

        while(!q.isEmpty()) {
            int qSize = q.size();

            for (int i = 0; i < qSize; i++) {
                int num = q.remove();

                // 범위 넘음
                if (num > B)
                    continue;

                // 정답
                if (num == B) {
                    found = true;
                    break;
                }

                q.add(num * 2);
                if (num < 1e8)
                    q.add(10 * num + 1);
            }

            if (found) {
                ans = cnt;
                break;
            }

            cnt++;
        }

        System.out.println(ans);
    }
}
