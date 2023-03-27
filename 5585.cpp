#include <iostream>

using namespace std;

int money_unit[6] = { 500, 100, 50, 10, 5, 1 };

int main(int argc, char* argv[]) {

	int money = 0;
	int result = 0;
	cin >> money;

	money = 1000 - money;

	for (int i = 0; i < 6; i++) {
		int count = money / money_unit[i];
		//cout << count << endl;

		result += count;
		money %= money_unit[i];
	}

	cout << result << endl;
	

	return 0;
}
