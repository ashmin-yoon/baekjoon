#include <iostream>
#include <map>
using namespace std;
const int MAX_SIZE = 100000;

// 컴파일 옵션
// g++ -std=c++17

int N, M;
map<string, string> myData;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	string url, passwd;
	for (int i = 0; i < N; i++) {
		cin >> url >> passwd;
		myData.insert({url, passwd});
	}
}

int main() {
	FastIO();
	Input();

	string target;
	map<string, string>::iterator search;
	for (int i = 0; i < M; i++) {
		cin >> target;
		search = myData.find(target);
		if (search != myData.end()) {
			cout << search->second << "\n";
		}
	}

	return 0;
}
