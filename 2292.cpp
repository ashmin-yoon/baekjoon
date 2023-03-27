#include <iostream>

using namespace std;

int main() {

	int num;
	cin >> num;

	int value = 1;
	int level = 1;
	int plus = 6;

	while(num > value) {
		level++;
		value += plus;
		plus += 6;	
	}

	cout << level << endl;;

	return 0;
}
