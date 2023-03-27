#include <iostream>
#define INF 987654321

using namespace std;

bool prime_num[10001];

void PrimeNumSetting() {
	prime_num[0] = false;
	prime_num[1] = false;

	for (int i = 2; i < 10001; i++) 
	{
		if (prime_num[i] == false)
			continue;

		// i의 배수들은 소수가 아님
		for (int j = 2; i*j < 10001; j++) {
			prime_num[i*j] = false;
		}
	}
}

int main() {
	fill(prime_num, prime_num+10001, 1);

	PrimeNumSetting(); // 세팅
	int start, end;
	cin >> start >> end;

	int sum = 0;
	int min_v = INF;
	for (int i = start; i <= end; i++) {
		if (prime_num[i])
		{
			sum += i;
		}
	}

	if (sum == 0) {
		cout << -1 << endl;
		exit(0);
	}
	cout << sum << endl;

	for (int i = start; i <= end; i++) {
		if (prime_num[i])
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}
