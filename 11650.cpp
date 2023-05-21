#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > v;

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {

	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}

	return p1.first < p2.first;
}

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	int n1, n2;
	for (int i = 0; i < N; i++) {
		cin >> n1 >> n2;
		v.push_back(make_pair(n1, n2));
	}
}

int main() {

	FastIO();
	Input();

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}
