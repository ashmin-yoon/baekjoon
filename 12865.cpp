#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;
const int MAX_SIZE = 100001;

/*
	 알고리즘 문제해결 전략1
	 DP - 여행짐싸기 참고

	 시간이 지나서 안 보고 풀 수 있도록
	 연습 필요
 */

int N, K;

int weight[100];
int value[100];
int cache[MAX_SIZE][100];


void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> weight[i] >> value[i];
	}
}

void Init() {
	for (int  i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < 100; j++) {
			cache[i][j] = -1;
		}
	}
}

// 남은 용량이 capacity 일 때, item 이후의 물건들을
// 담아 얻을 수 있는 최대 가치의 합 반환
int pack(int capacity, int item) {
	// cout << "pack(" << capacity << ", " << item << ")" << endl;
	// 기저 사례 - 더 담을 물건 없음
	if (item == N) {
		return 0;
	}

	int& ret = cache[capacity][item];
	if (ret != -1) return ret; // 이전에 구함

	// 이 물건을 담지 않을 때
	ret = pack(capacity, item + 1);

	// 이 물건을 담을 때
	if (capacity >= weight[item]) {
		ret = max(ret, pack(capacity - weight[item], item + 1) + value[item]);
	}

	return ret;

}

void PrintCache() {
	for (int w = 0; w <= K; w++) {
		for (int i = 0; i < N; i++) {
			cout << "cache["<<w<<"]["<<i<<"] = " << cache[w][i] << endl;
		}
	}
}

int main() {
	FastIO();
	Init();
	Input();
	cout << pack(K, 0);

	return 0;
}
