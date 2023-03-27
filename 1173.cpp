#include <iostream>

using namespace std;

int main() {
	int N, m, M, T, R;
	N = m = M = T = R = 0;

	cin >> N;
	cin >> m >> M;
	cin >> T >> R;

	int pulsation = m;
	int time = 0;

	if (m + T > M)
	{
		N = 0;
		time = -1;
	}

	while(N)
	{
		if (pulsation + T > M)
		{
			time++;
			pulsation -= R;
			if (pulsation < m)
				pulsation = m;
			continue;
		}

		N--;
		pulsation += T;
		time++;
	}

	cout << time;
	

	return 0;
}
