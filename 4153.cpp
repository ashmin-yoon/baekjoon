#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v(3, 0);

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}


void swap(int& n1, int& n2) {
	int tmp = 0;
	if (n1 > n2) {
	}
}

bool isRightTriangle(vector<int>& v) {
	sort(v.begin(), v.end());

	int a = v[0] * v[0];
	int b = v[1] * v[1];
	int c = v[2] * v[2];

	if (c == a + b)
		return true;
	return false;

}

int main() {

	FastIO();

	while (true) {
		cin >> v[0] >> v[1] >> v[2];
		if (v[0] == 0 && v[1] == 0 && v[2] == 0)
			break;

		if(isRightTriangle(v))
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return 0;
}
