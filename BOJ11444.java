import java.io.*;
import java.util.HashMap;
import java.util.Map;

public class BOJ11444 {
    private static final int MOD = 1000000007;
    private static Map<Long, Integer> map = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));;
        Long n = Long.parseLong(br.readLine());

        // 초기값 설정
        map.put(0L, 0);
        map.put(1L, 1);
        map.put(2L, 1);
        map.put(3L, 2);
        map.put(4L, 3);
        System.out.println(solution(n));
    }

    // 해당 문제는 공식이 필요하여 검색함
    // 도가뉴 항등식 참고
    // F(m + n) = F(m - 1) * F(n) + F(m) * F(n + 1);
    private static Long solution(Long n) {
//        if (n == 0)
//            return 0L;
//        if (n == 1)
//            return 1L;
//        if (n == 2)
//            return 1L;
//        if (n == 3)
//            return 2L;

        // 기존에 구한 값인지 확인
        Integer value = map.get(n);
        if (value != null) {
            return value.longValue();
        }

        Long ans;

        Long minus1 = solution(n / 2 - 1);
        Long origin = solution(n / 2);
        Long plus1 = (minus1 + origin) % MOD;
        map.put(n / 2 - 1, minus1.intValue());
        map.put(n / 2, origin.intValue());
        map.put(n / 2 + 1, plus1.intValue());

        // n 짝수
        if (n % 2 == 0)
        {
            ans = ((minus1 * origin) % MOD + (origin * plus1) % MOD) % MOD;
        }

        // 홀수
        else {
            Long plus2 = (origin + plus1) % MOD;
            map.put(n / 2 + 2, plus2.intValue());
            ans = ((minus1 * plus1) % MOD + (origin * plus2) % MOD) % MOD;
        }
        map.put(ans, ans.intValue());
        return ans;
    }

}

