#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> score;
int N;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	int _score;
	for (int i = 0; i < N; i++) {
		cin >> _score;
		score.push_back(_score);
	}
}

int Solution() {
	int sum = 0;
	int disregard_cnt = score.size() * 0.15 + 0.5; // 무시 개수(상, 하 각각 따로)
	int cnt = score.size() - 2 * disregard_cnt;
	cout << "cnt = " << cnt<< endl;

	// 정렬
	sort(score.begin(), score.end()); 

	// 앞 뒤 짤림
	for (int i = 0; i < cnt; i++) {
		sum += score[i + disregard_cnt];
	}

	// 0 나누기 때문에 틀림
	if (cnt == 0) {
		return 0;
	}

	int ans = (((double)sum / cnt) + 0.5);
	return ans;
}

int main() {
	FastIO();
	Input();
	cout << Solution();

	return 0;
}
