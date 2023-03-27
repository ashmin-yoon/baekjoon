#include <iostream>
#include <vector>

using namespace std;

long long answer[41][2] = { {1, 0}, {0, 1} };

int main() {

	int num;
	cin >> num;

	for (int i = 2; i < 41; i++) {
		answer[i][0] = answer[i - 1][0] + answer[i - 2][0];
		answer[i][1] = answer[i - 1][1] + answer[i - 2][1];
	}

	vector<int> input(num);
	for (int i = 0; i < num; i++) {
		cin >> input[i];
	}

	for (int i = 0; i < num; i++) {
		int idx = input[i];
		cout << answer[idx][0] << " " << answer[idx][1] << endl;
	}


	return 0;
}
