#include <iostream>

using namespace std;

int main() {

	int h;
	int move;
	int slip;
	cin >> move >> slip;
	cin >> h;

	h = h - move;

	int ans = h / (move - slip) + 1;
	if (h % (move - slip)) {
		ans += 1;
	}
	cout << ans << endl;


	return 0;
}
