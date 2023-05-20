#include <iostream>
using namespace std;

int main() {

	bool isAscending = true;
	bool isDescending= true;
	int arr[8];
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < 8; i++) {
		if (arr[i] != arr[i - 1] + 1)
			isAscending = false;
		if (arr[i] != arr[i - 1] - 1)
			isDescending = false;
	}

	if (isAscending)
		cout << "ascending" << endl;
	else if (isDescending)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;

}
