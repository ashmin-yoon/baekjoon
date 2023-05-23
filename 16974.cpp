#include <iostream>
using namespace std;
const int MAX_SIZE = 51;

long long level[MAX_SIZE];
long long patty[MAX_SIZE];
long long N, X;

// 세팅까지는 직접 짜고 코드 참고
// 주의 데이터 자료형 크기

void SetLevel() {

	level[0] = 1;
	patty[0] = 1;

	level[1] = 5;
	patty[1] = 3;
	
	for (int i = 2; i < MAX_SIZE; i++) {
		level[i] = 3 + (2 * level[i - 1]);
		patty[i] = 1 + (2 * patty[i - 1]);
	}
}


long long FindAns(int n, long long x) {
	long long patty_cnt = 0;

	if (x <= 0 || n < 0)
		return 0;

	if (n == 0) {
		return 1;
	}

	// 가장 아래 번 먹음
	x--;

	// 아래 레벨 버거랑 같음
	if (x == level[n - 1]) {
		patty_cnt += patty[n - 1];
	}
	// 먹을 수 있는 양 적음
	else if (x < level[n - 1]) {
		patty_cnt += FindAns(n - 1, x);
	}
	else { // 먹을 수 있는 양 많음(아래 레벨 하나 먹고 남는양)
		patty_cnt += patty[n - 1] + 1;
		x -= (level[n - 1] + 1);

		// 남은 양 찾기
		patty_cnt += FindAns(n - 1, x);
	}

	return patty_cnt;
}

int main() {
	cin >> N >> X;

	SetLevel();
	cout << FindAns(N, X);

	return 0;
}
