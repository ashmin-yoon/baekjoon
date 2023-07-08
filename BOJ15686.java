import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ15686 {
    private static int N, M;
    private static final int MAX_SIZE = 51;
    private static final int SPACE = 0;
    private static final int HOME = 1;
    private static final int CHICKEN = 2;

    private static List<Point> homes = new ArrayList<>();
    private static List<Point> chickens = new ArrayList<>();
    private static int[] selected = new int[13];

    static class Point {
        int y;
        int x;
        public Point(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        System.out.println(solution(0, 0));
    }

    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        for (int i = 1; i <= N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                int value = Integer.parseInt(st.nextToken());
                if (value == CHICKEN) {
                    chickens.add(new Point(i, j));
                }
                if (value == HOME) {
                    homes.add(new Point(i, j));
                }
            }
        }
    }

    private static int calcDist() {
        int dist[] = new int[homes.size()];
        Arrays.fill(dist, 987654321);

        for (int i = 0; i < M; i++) {
            Point chicken = chickens.get(selected[i]);
            for (int j = 0; j < homes.size(); j++) {
                dist[j] = Math.min(dist[j], getDistance(chicken, homes.get(j)));
            }
        }

        int rev = 0;
        for (int j = 0; j < homes.size(); j++) {
            rev += dist[j];
        }
        return rev;
    }



    private static int solution(int index, int count) {
        int rev = 987654321;
        if (count == M) {
            return calcDist();
        }

        // 치킨집 선택
        for (int i = index; i < chickens.size(); i++) {
            selected[count] = i;
            rev = Math.min(rev, solution(i + 1, count + 1));
        }

        return rev;
    }

    private static int getDistance(Point p1, Point p2) {
        return Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y);
    }

}
