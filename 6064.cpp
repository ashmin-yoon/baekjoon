#include <iostream>

using namespace std;

int Solution(int M, int N, int x, int y) 
{
	int ans;
	if (M == 1 && N == 1)
	{
		if (x > 1 || y > 1)
			return -1;
		return 1;
	}

	if (M > N)
	{
		for (int i = 0; ; i++) 
		{
			ans = x + M * i;
			if (ans > M * N)
				return -1;
			int tmp = ans % N == 0 ? N : ans % N;
			if (y == tmp)
				return ans;
		}
	}
	else
	{
		for (int i = 0; ; i++) 
		{
			ans = y + N * i;
			if (ans > M * N)
				return -1;
			int tmp = ans % M == 0 ? M : ans % M;
			if (x == tmp)
				return ans;
		}
	}

	// 정답이 없을 때
	return -1;
}

int main() 
{

	int T;
	cin >> T;

	int M, N;
	int x, y;

	while(T--)
	{
		cin >> M >> N;
		cin >> x >> y;
		cout << Solution(M, N, x, y) << endl;
	}
	return 0;
}
