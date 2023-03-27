#include <iostream>
#include <algorithm>
#define INF 987654321

using namespace std;

int main() {

	int kg;
	cin >> kg;
	
	int count = INF;

	for (int i = 0; i < (kg / 5 + 1); i++) {
		int jx3 = kg - i * 5;
		if (jx3 % 3 == 0) {
			int j = jx3 / 3;
			count = min(count, i + j);
		}
	}

	if (count == INF)
	{
		count = -1;
	}

	cout << count << endl;


	return 0;
}
