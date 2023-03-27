#include <iostream>
#include <vector>

using namespace std;

int main() {
	int num;
	cin >> num;

	vector<double> v(num, 0);
	double sum = 0;
	int max = 0;
	for (int i = 0; i < num; i++) {
		cin >> v[i];
		sum += v[i];
		if (max < v[i])
			max = v[i];
	}

	sum = sum / max * 100 / num;
	cout << sum << endl;

	return 0;
}
