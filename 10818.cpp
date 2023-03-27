#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;

	int* arr = new int [num];

		for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}


	int min, max;
	min = arr[0];
	max = arr[0];


	for (int i = 1; i < num; i++) {
		if (min > arr[i])
			min = arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	cout << min << " " << max << endl;

	delete[] arr;
	return 0;
}
