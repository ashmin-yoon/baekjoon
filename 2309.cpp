#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int sum = 0;
	vector<int> v;

	for (int i = 0; i < 9; i++) {
		cin >> n;
		sum += n;
		v.push_back(n);
	}

	sum -= 100;
	sort(v.begin(), v.end());

	vector<int>::iterator left = v.begin();
	vector<int>::iterator right = v.end() - 1;

	while(left < right) {
		if(*left + *right == sum) break;
		else if (sum < *left + *right) {
			right--;
		} else {
			left++;
		}
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		if (it == left || it == right)
			continue;
		cout << *it << endl;
	}


	return 0;
}
