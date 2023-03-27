#include <iostream>

using namespace std;

int main() {

	string A;
	string B;

	cin >> A >> B;

	if (A.length() < B.length())
	{
		for (int i = 0; i < A.length(); i++) {
		}
	}

	string ans = "";
	int next_num = 0; // 올림 수
	int i = 0;
	while(i < A.length() || i < B.length()) {
		int num_a = 0;
		int num_b = 0;

		if (i < A.length())
			num_a = A[A.length() - i - 1] - '0';
		if (i < B.length())
			num_b = B[B.length() - i - 1] - '0';

		int sum = num_a + num_b + next_num;
		next_num = sum / 10;
		ans += (sum % 10) + '0'; // 자리에 알맞은 값 - 역순으로 쓰임

		i++;
	}
	if (next_num) {
		ans += next_num + '0';
	}

	for (int i = 0; i < ans.length(); i++) {
		cout << ans[ans.length() - i - 1];
	}
	cout << endl;




	return 0;
}
