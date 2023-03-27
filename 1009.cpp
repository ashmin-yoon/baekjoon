#include <iostream>
#include <vector>

using namespace std;


int main() {
	int num;
	cin >> num;

	int a, b, result;
	vector<int> answer;

	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		result = 1;
		for (int j = 0; j < b; j++) {
			result *= a;
			result %= 10;	
			// 값의 범위를 넘어가기 때문에 일의 자리만 계산
		}
		if (result % 10 == 0)
			answer.push_back(10);
		else
			answer.push_back(result % 10);
	}

	for (int i = 0; i < num; i++) {
		cout << answer[i] << endl;
	}

	return 0;
}
