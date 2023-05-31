#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;

map<string, string> m1;
map<string, string> m2;


void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() {
	cin >> N >> M;
	string name;
	for (int i = 1; i <= N; i++) {
		cin >> name;
		m1.insert(make_pair(name, to_string(i)));
		m2.insert(make_pair(to_string(i), name));
	}
}

int main() {
	FastIO();
	Input();

	string question;
	for (int i = 0; i < M; i++) {
		cin >> question;

		// 문자일 경우
		if ('A' <= question[0] && question[0] <= 'Z') {
			cout << m1.find(question)->second << "\n";
		}
		// 숫자일 경우
		else {
			cout << m2.find(question)->second << "\n";
		}
	}

	return 0;
}
