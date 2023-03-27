#include <iostream>
#include <algorithm>

using namespace std;

bool alpha[26];
int ans = 0;

void Init() {
	fill(alpha, alpha+26, 0);	
}

void Solution(string str) {
	int index = 0;
	int flag = true;
	char pre;
	for (int i = 0; i < str.length(); i++) {
		index = str[i] - 'a';

		if (pre == str[i])
			continue;
		
		// 이전 문자와 다른데 alpha 가 true 상태이면 return
		if(alpha[index]) {
			return;
		}

		alpha[index] = true;
		pre = str[i];
	}

	ans++;
}

using namespace std;

int main() {
	int num;
	cin >> num;

	string str;
	for (int i = 0; i < num; i++) {
		cin >> str;
		Init();
		Solution(str);
	}

	cout << ans << endl;

	return 0;
}
