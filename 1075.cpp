#include <iostream>

using namespace std;

int main() {
	int n;
	int f;

	cin >> n >> f;

	n = n - n % 100;
	int i = 0;
	for (; n % f; n++);

	int answer = n % 100;
	if (answer < 10)
		cout << 0;
	cout << answer << endl;




	return 0;
}
