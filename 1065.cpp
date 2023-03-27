#include <iostream>

using namespace std;

int hansoo[1001]; // 각 자리별 한 수 개수 저장

bool CheckHansoo(int num) {
	int diff = num / 10 % 10 - num % 10;
	while(num / 10) {
		if (diff != num / 10 % 10 - num % 10)
			return false;
		num = num / 10;
	}
	return true;
}

int main() {
	int num;
	cin >> num;

	int count = 0;
	for (int i = 1; i <= num; i++) {
		if (CheckHansoo(i))
		{
			//cout << i << endl;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}
