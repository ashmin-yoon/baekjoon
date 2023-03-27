#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int num;
	cin >> num;

	vector<int> v1(num);
	vector<int> v2(num);

	for (int i = 0; i < num; i++) {
		cin >> v1[i];
	}

	for (int i = 0; i < num; i++) {
		cin >> v2[i];
	}


	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end(), greater<int>());
	
	int sum = 0;
	for (int i = 0; i < num; i++) {
		v1[i] *= v2[i];
		sum += v1[i];
	}

	cout << sum;

	return 0;
}
