#include <iostream>

using namespace std;

// 참고 출처
// https://takeknowledge.tistory.com/20

int main() {
	int n1, n2;

	while(true) {
		cin >> n1 >> n2;
		if(cin.eof() == true)
			break;

		cout << n1 + n2 << endl;
	}

	return 0;
}
