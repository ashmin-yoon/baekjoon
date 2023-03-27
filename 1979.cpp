#include <iostream>
#include <vector>

using namespace std;

bool prime_num[1001];
int main() {

	fill(prime_num, prime_num+1001, 1);
	prime_num[0] = false;
	prime_num[1] = false;
	prime_num[2] = true;

	for (int i = 2; i < 1001; i++) {
		if (prime_num[i] == false)
			continue;
		int c = 2;
		while(i * c < 1001) {
			prime_num[i * c] = false;
			c++;
		}
	}

	int n;
	int tmp;
	int count = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (prime_num[tmp])
			count++;
	}

	cout << count << endl;


	return 0;
}
