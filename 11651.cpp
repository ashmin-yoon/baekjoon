#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int ,int> > v;

int N;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.second == p2.second) {
		return p1.first < p2.first;
	}
	return p1.second < p2.second;
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
}

void Print() {
	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}

int main() {
	FastIO();
	Input();
	sort(v.begin(), v.end(), cmp);
	Print();

	return 0;
}
