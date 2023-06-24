#include <iostream>
#include <map>
using namespace std;
// g++ -std=c++17

int T;
int N;
map<string, int> kind;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N;
	string item;
	string kindOfItem;
	map<string, int>::iterator search;
	for (int i = 0; i < N; i++) {
		cin >> item >> kindOfItem;

		search = kind.find(kindOfItem);
		// 찾아서 있으면 개수 증가
		if (search != kind.end()) {
			search->second++;
		}
		// 없으면 추가
		else {
			kind.insert({kindOfItem, 1});
		}
	}
}

int Solution() {
	if (N == 0) {
		return 0;
	}

	// 각 종류 수 + 1 을 전부 곱하고
	// 1을 빼면(아무 것도 입지 않음) 가능한 경우의 수
	int count = 1;
	map<string, int>::iterator it;
	for (it = kind.begin(); it != kind.end(); it++) {
		count *= it->second + 1;
	}

	count--;
	return count;
}

int main() {

	FastIO();

	cin >> T;
	while(T--) {
		kind.clear();
		Input();
		int ans = Solution();
		cout << ans << "\n";
	}

	return 0;
}
