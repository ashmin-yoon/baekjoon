#include <iostream>
// 풀이 참고 https://unfunhy.tistory.com/m/36

using namespace std;

int Solution(int n) {
	int value = 1;
	int count = 1;
	while (true) {
		value = value % n;
		if (value == 0)
		{
			return count;
		}

		value *= 10;
		value += 1;
		count++;
	}
}


int main() {

	int n = 0;

	while(true) {
		cin >> n;
		if (cin.eof() == true) break;
		cout << Solution(n) << endl;
	}

	return 0;
}
