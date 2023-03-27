#include <iostream>
using namespace std;
const int INF = 987654321;

int main() {

	string a;
	string b;

	cin >> a;
	cin >> b;

	int ans = INF;
	for (int i = 0; i < b.size(); i++)
	{
		int count = 0;
		if (b.size() - i < a.size())
			break;

		for (int j = 0; j < a.size(); j++)
			if (a[j] != b[i + j])
				count++;

		ans = min(ans, count);
	}

	cout << ans;

	return 0;
}
