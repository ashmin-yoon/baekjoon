#include <iostream>

using namespace std;

int main() {

	int T;
	cin >> T;

	int n1, n2;
	for (int i = 0; i < T; i++)
	{
		cin >> n1 >> n2;
		cout << "Case #" << i+1 << ": " << n1+n2 << endl;
	}

	return 0;
}
