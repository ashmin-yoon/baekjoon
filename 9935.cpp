#include <iostream>
using namespace std;
const int MAX_SIZE = 1000000;

char ch[MAX_SIZE];
int top = -1;
string str;
string bomb;

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Solution() {
	for (int i = 0; i < str.size(); i++) {
		ch[++top] = str[i];

		// 확인 후 제거
		while ((top + 1) >= bomb.size() && ch[top] == bomb.back()) {
			bool isEqual = true;
			// 문자 비교
			for (int j = 0; j < bomb.size(); j++) {
				if (ch[top - j] != bomb[bomb.size() - 1 - j]) {
					isEqual = false;
					break;
				}
			}

			if (isEqual) {
				top -= bomb.size();
			}
			else {
				break;
			}
		}
		
	}

}

int main() {
	FastIO();
	cin >> str >> bomb;

	Solution();
	
	if (top == -1) { printf("FRULA"); }
	else {
		for (int i = 0; i <= top; i++) {
			printf("%c", ch[i]);
		}
	}

	return 0;
}
