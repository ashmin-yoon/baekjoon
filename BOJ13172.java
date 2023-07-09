import java.io.*;
import java.util.StringTokenizer;

// 해당 문제는 그냥 답 확인함
// 문제에서 원하는 바를 정확히 인지 하지 못함
// 정수론 및 기타 수학적 지식 부족

// 출처
// https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-13172%EB%B2%88-%CE%A3-CC:ㅈ
// 참고 자료
// https://blog.naver.com/shwoghk14/222995304775

public class BOJ13172 {
    private static final int MOD = 1000000007; // 10억 + 7
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());

        long ans = 0;
        for (int i = 0; i < M; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            Long b = Long.parseLong(st.nextToken()); // N 면체
            Long a = Long.parseLong(st.nextToken()); // S 합
            long _gcd = gcd(a, b);

            // 약분 => a, b는 서로소
            a /= _gcd;
            b /= _gcd;

            // b의 모듈러 곱세에 대한 역원
            long mmiB = getModularMultiplicativeInverse(b.intValue(), MOD);
            ans += a * mmiB % MOD;
            ans %= MOD;
        }
        System.out.println(ans);
    }

    // 최대 공약수
    // the greatest common divisor
    /* 동일 코드
      if (a < b) { swap a, b }
      while(b != 0) {
        rest = a % b;
        a = b;
        b = rest;
      }
      return a;
    */
    private static long gcd(long a, long b) {
        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    // 나머지 연산의 역원
    // a^(n-2) === a^-1 (mod n)
    private static long getModularMultiplicativeInverse(int num, int mod) {
        return pow(num, mod - 2);
    }

    // base 밑
    // exp 지수 (exponent)
    private static long pow(int base, int exp) {
        if (exp == 0) return 1;
        if (exp == 1) return base;

        long divided = pow(base, exp / 2);
        if (exp % 2 == 0) // 지수 짝수
            return (divided * divided) % MOD;
        else // 지수 홀수
            return ((divided * divided) % MOD) * base % MOD;
    }

}
