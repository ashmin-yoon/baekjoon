#include <iostream>
#include <algorithm>

using namespace std;

int value[12] = { 0, 1, 2, 4 };

int main(int argc, char* argv[]) {

	int num = 0;
	cin >> num;

	for (int i = 4; i < 12; i++) {
		value[i] = value[i - 3] + value[i - 2] + value[i - 1];
	}	

	int * index = new int [num];
	for (int i = 0; i < num; i++) {
		cin >> index[i];
	}

	for (int i = 0; i < num; i++) {
		cout << value[index[i]] << endl;
	}

	delete [] index;
	return 0;
}
