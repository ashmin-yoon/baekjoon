#include <iostream>
#include <vector>
using namespace std;

int K;
int ans;
vector<int> v;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Solution() {
	cin >> K;

	int value;

	for (int i = 0; i < K; i++) {
		cin >> value;
		if (value == 0) v.pop_back();
		else v.push_back(value);
	}


	for (int i = 0; i < v.size(); i++) {
		ans += v[i];
	}

}

int main() {
	FastIO();
	Solution();

	cout << ans;

	return 0;
}
