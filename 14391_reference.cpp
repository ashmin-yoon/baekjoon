#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int MAX = 4;
const int MINUS_INF = -987654321;

int N; 	// 세로 크기 Row
int M;	// 가로 크기 Col
int ROW;
int COL;
int value[MAX][MAX];
int ans;

int main() {
	cin >> N >> M;
	ROW = N;
	COL = M;

	char ch;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ch;
			value[i][j] = ch - '0';
		}
	}

	/*
https://hongjw1938.tistory.com/115
https://kingsubin.tistory.com/308
		 */
	// 분석하기

	// 가로로 이어지면 0, 세로로 이어지면 1이라고 가정하자.
	// n*m이 주어지므로 n*m-1번 << 연산을 하면 모든 비트가 1이 되는 경우를 찾을 수 있다.
	// i = 0이면 모두 가로로만 찢는 경우이며, 모두 1이면 세로로만 찢는 경우이다.
	int k = 0;
	for (int tc = 0; tc < (1 << ROW * COL); tc++) {
		int sum = 0;
		// 가로 합
		for (int i = 0; i < ROW; i++) {
			int lineSum = 0;
			for (int j = 0; j < COL; j++) {
				k = i * COL + j;
				if ((tc & (1 << k)) == 0)
				{
					lineSum = lineSum * 10 + value[i][j];
				}
				else
				{
					sum += lineSum;
					lineSum = 0;
				}
			}
			sum += lineSum;
		}

		// 세로 합
		for (int j = 0; j < COL; j++) {
			int lineSum = 0;
			for (int i = 0; i < ROW; i++) {
				k = i * COL + j;

				if ((tc & (1 << k)) != 0)
				{
					lineSum = lineSum * 10 + value[i][j];
				}
				else
				{
					sum += lineSum;
					lineSum = 0;
				}
			}
			sum += lineSum;
		}

		ans = max(ans, sum);
		if (ans == sum) {
			cout << tc << " ";
			cout << sum << endl;
		}
	}
	cout << ans << endl;

	return 0;
}
