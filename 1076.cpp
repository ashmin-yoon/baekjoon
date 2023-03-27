#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> m;


int main() {
	m["black"] = 0;
	m["brown"] = 1;
	m["red"] = 2;
	m["orange"] = 3;
	m["yellow"] = 4;
	m["green"] = 5;
	m["blue"] = 6;
	m["violet"] = 7;
	m["grey"] = 8;
	m["white"] = 9;


	string first, second, third;
	cin >> first;
	cin >> second;
	cin >> third;

	int value = 0;
	value = m[first] * 10 + m[second];

	string ans = to_string(value);
	if (ans != "0") {
		for (int i = 0; i < m[third]; i++) {
			ans += "0";
		}
	}

	cout << ans;
	return 0;
}
