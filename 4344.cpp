#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	cout << fixed;
	cout.precision(3); // 소수점 셋째자리까지 고정

	int num;
	while(T--) {
		cin >> num;
		vector<int> v(num, 0);
		int sum = 0;
		double avg = 0.0;
		int count = 0;

		for (int i = 0; i < num; i++) {
			cin >> v[i];
			sum += v[i];
		}
		avg = (double)sum / num;

		for (int i = 0; i < num; i++) {
			if (v[i] > avg)
				count++;
		}

		cout << (double)count * 100 / num << "%" << endl;

	}

	return 0;
}
