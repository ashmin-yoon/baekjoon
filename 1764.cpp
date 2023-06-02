#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
map<string, string> m;
vector<string> ans;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

int main() {
	FastIO();

	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		m.insert(make_pair(str, str));
	}

	for (int j = 0; j < M; j++) {
		cin >> str;
		if (m.find(str) != m.end()) {
			ans.push_back(str);
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}
