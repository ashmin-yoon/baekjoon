#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N;
vector<int> permutation;

bool next_permutation(vector<int>& v) {
	bool isExisting = false;
	int index = -1;

	for (int i = v.size() - 1; i > 0; i--) {
		if (v[i-1] < v[i]) {
			isExisting = true;
			index = i-1;
			break;
		}	
	}

	if (isExisting == false) {
		return isExisting;
	}

	int value = v[index];
	sort(v.begin() + index + 1, v.end());

	for (int i = index; i < v.size(); i++) {
		if (v[i] > v[index]) {
			int tmp = v[i];
			v[i] = v[index];
			v[index] = tmp;
			break;
		}
	}
	
	sort(v.begin() + index + 1, v.end());
	return isExisting;
}

int main() {
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		permutation.push_back(tmp);
	}

	bool result = next_permutation(permutation);

	if (result)
	{
		for (vector<int>::iterator it = permutation.begin(); it != permutation.end(); it++) {
			cout << *it << " ";
		}
		cout << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}
