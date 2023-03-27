#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int ARR_SIZE = 10001;
	int* count = new int [ARR_SIZE];
	fill(count, count+ARR_SIZE, 0);

	int tmp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		count[tmp]++;
	}

	for (int i = 1; i < ARR_SIZE; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << i << "\n";
		}
	}
	

	delete [] count;

	return 0;
}
