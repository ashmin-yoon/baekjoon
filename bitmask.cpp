//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int n = 4;

string a[4] = {"사과", "딸기", "포도", "배"};

void go(int num) {
	string ret = "";
	for (int i = 0; i < 4; i++) {
		cout << "go(" << num << ") for 1 << " << i << " = " << (1 << i) << endl;
		if (num & (1 << i))
			ret += a[i] + " ";
	}

	cout << ret << '\n';
	return;
}


int main() {
	for (int i = 1; i < n; i++) {
		cout << "메인 for 1 << " << i << " = " << (1 << i) << endl;
		go(1 | (1 << i));
	}
}
