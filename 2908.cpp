#include <iostream>

using namespace std;

int sangsoo_compare(int n1, int n2) {
	int num1 = n1;
	int num2 = n2;
	int ans;
	for (int i = 0; i < 3; i++) {
		if (num1 % 10 < num2 % 10) {
			ans = n2;
			break;
		}
		if (num1 % 10 > num2 % 10) {
			ans = n1;
			break;
		}
		num1 /= 10;
		num2 /= 10;
	}

	return ans;
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;

	int ans = sangsoo_compare(n1, n2);
	while(ans) {
		cout << ans % 10;
		ans = ans / 10;
	}


	return 0;
}
