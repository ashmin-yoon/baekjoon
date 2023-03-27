#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> v;
vector<int> selected;
vector<int> visit;

int ans = 0;

void dfs(int count) {
	if (count == v.size()) {
		int sum = 0;
		for (int i = 0; i < count - 1; i++) {
			sum += abs(selected[i] - selected[i+1]);
		}
		ans = max(ans, sum);
		return;
	}	

	for (int i = 0; i < v.size(); i++) {
		if(visit[i]) continue;
		visit[i] = true;
		selected.push_back(v[i]);
		dfs(count + 1);
		selected.pop_back();
		visit[i] = false;
	}
}

int main() {
	int N;
	cin >> N;

	int tmp;
	for(int i =0 ; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
		visit.push_back(false);
	}

	sort(v.begin(), v.end());

	dfs(0);
	cout << ans << endl;

	return 0;
}
