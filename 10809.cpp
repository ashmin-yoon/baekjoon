#include <iostream>
#include <vector>

using namespace std;

int main() {

	string str;
	cin >> str;

	vector<int> v(26, -1);
	for (int i = 0; i < str.size(); i++) {
		if (v[str[i] - 'a'] == -1)
			v[str[i] - 'a'] = i;	
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}
