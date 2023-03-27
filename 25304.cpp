#include <iostream>

using namespace std;

int main() {
	int total;
	int type;

	cin >> total >> type;

	int price;
	int count;
	for (int i = 0; i < type; i++) {
		cin >> price >> count;
		total -= price * count;
	}

	if (total == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;


	return 0;
}
