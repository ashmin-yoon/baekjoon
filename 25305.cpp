#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int num;
	int order;
	int* arr;

	cin >> num;
	cin >> order;

	arr = new int [num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + num);
	cout << arr[num - order] << endl;

	delete [] arr;

	return 0;
}
