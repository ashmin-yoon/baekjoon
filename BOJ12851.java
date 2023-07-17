import java.io.*;
import java.util.*;

// 쉬우면서도
// 많이 헷갈리는 문제

// 53% 반례는 0 10  cnt[0] 에서 2로 되었음

public class BOJ12851 {
    private static final int MAX_SIZE = 100501;
    private static final int INF = 987654321;
    private static int N, K;
    private static int[] cnt = new int[MAX_SIZE];
    private static int[] visited = new int[MAX_SIZE];
    private static int minTime = INF;

    public static void main(String[] args) throws IOException {
        input();
        solution();
        System.out.println(minTime);
        System.out.println(cnt[K]);
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
    }

    static class Data {
        int pos;
        int prev;
        public Data(int pos, int prev) {
            this.pos = pos;
            this.prev = prev;
        }
    }
    private static void solution() {
        // 변수 초기화
        Arrays.fill(cnt, 0);
        Arrays.fill(visited, -1);
        minTime = 0;
        boolean exitFlag = false;

        Queue<Data> q = new LinkedList<>();
        q.add(new Data(N, 100005));
        cnt[100005] = 1; // 0 자리도 사용되기에 변경
        visited[N] = 0;


        while (!q.isEmpty()) {
            int qSize = q.size();
//            System.out.println("=============== time = " + minTime);

            while (qSize-- > 0) {
                Data data = q.remove();
                int pos = data.pos;

                cnt[pos] += cnt[data.prev];
//                System.out.println("pos = " + pos + ", cnt[pos] = " + cnt[pos]);

                // 도착지점 확인
                if (pos == K) {
                    exitFlag = true;
                }

                if (pos + 1 < MAX_SIZE) {
                    // 첫 방문
                    if (visited[pos + 1] == -1) {
                        q.add(new Data(pos + 1, data.pos));
                        visited[pos + 1] = minTime + 1;
                    }
                    // 현재 시간에서의 추가 방문
                    else if (visited[pos + 1] == minTime + 1) {
                        cnt[pos + 1] += cnt[pos];
                    }
                }
                if (pos - 1 >= 0) {
                    if (visited[pos - 1] == -1) {
                        q.add(new Data(pos - 1, data.pos));
                        visited[pos - 1] = minTime + 1;
                    }
                    else if (visited[pos - 1] == minTime + 1) {
                        cnt[pos - 1] += cnt[pos];
                    }
                }
                if (pos * 2 < MAX_SIZE) {
                    if (visited[pos * 2] == -1) {
                        q.add(new Data(pos * 2, data.pos));
                        visited[pos * 2] = minTime + 1;
                    }
                    else if (visited[pos * 2] == minTime + 1) {
                        cnt[pos * 2] += cnt[pos];
                    }
                }
            }

            if (exitFlag) {
                break;
            }

            minTime++;
        }
    }
}
