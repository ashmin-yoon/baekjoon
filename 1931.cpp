#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 100000;

int N;
vector<pair<int, int> > v;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;

	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}
}

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {

	// 종료시간 기준 오름차순 우선
	// 두번째로 시작시간 오름차순
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}

	return p1.second < p2.second;
}

void Solution() {
	int cnt = 0;

	sort(v.begin(), v.end(), cmp); // 정렬

	int end = 0;

	for (int i = 0; i < N; i++) {
		if (v[i].first >= end) {
			end = v[i].second;
			cnt++;
		}
	}

	cout << cnt;
}

int main() {
	FastIO();
	Input();
	Solution();

	return 0;
}
