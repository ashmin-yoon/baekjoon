import java.io.*;
import java.util.StringTokenizer;
public class BOJ2166 {

    private static final int MAX_SIZE = 10001;
    private static int N;
    private static long [] posX = new long [MAX_SIZE];
    private static long [] posY = new long [MAX_SIZE];
    public static void main(String args[]) throws IOException {
        // https://www.youtube.com/watch?v=0KjG8Pg6LGk
        // Shoelace Formula (Gauss's Area Formula)

        input();
        System.out.printf("%.1f", solution());
    }


    private static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());

        StringTokenizer st;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            posX[i] = Long.parseLong(st.nextToken());
            posY[i] = Long.parseLong(st.nextToken());
        }

        posX[N] = posX[0];
        posY[N] = posY[0];
    }

    private static double solution() {
        double area = 0.0f;

        for (int i = 0; i < N; i++) {
            area += posX[i] * posY[i + 1] ;
            area -= posY[i] * posX[i + 1];
        }

        area /= 2;
        return Math.abs(area);
    }
}
