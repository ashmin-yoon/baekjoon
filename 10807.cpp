#include <iostream>
using namespace std;

int N;
int countArr[201];

int main() {
	cin >> N;

	int number;
	for (int i = 0; i < N; i++) {
		cin >> number;
		countArr[number + 100]++;
	}

	cin >> number;
	cout << countArr[number + 100];



	return 0;
}
