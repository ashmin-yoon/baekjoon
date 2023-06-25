import java.io.*;

class BOJ5525 {
   public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      int N = Integer.parseInt(br.readLine());
      int M = Integer.parseInt(br.readLine());
      String S = br.readLine() + "  "; // 마지막 계산 편의를 위해 2 칸 추가

      int ans = 0;

      // S에 포함된 길이 긴 Px 구하기 그리고 계산
      int level = 0;
      for (int i = 0; i < S.length() - 2; i++) {
         if (S.charAt(i) == 'I' && S.charAt(i + 1) == 'O' && S.charAt(i + 2) == 'I') {
            level++;
            i++; // i 한 칸 더 증가
         }
         else if(level > 0) {
            // 레벨이 같거나 더 클 경우만
            if (level >= N) {
               ans += level - N + 1;
            }
            level = 0;
         }
      }

      System.out.print(ans);
      br.close();
   }
}