#include <iostream>
using namespace std;
const int MAX_SIZE = 31;

int N;
int DP[MAX_SIZE];

int main()
{
	cin >> N;
	DP[0] = DP[1] = 0;	
	DP[2] = 3;
	DP[4] = DP[2] + 2;

	// N이 홀수라면 못 채움
	for (int i = 4; i < MAX_SIZE; i+=2)
	{	
		DP[i] = DP[i-2] * 3 + 2; // 너비2 짜리 시작, 자기 자신 연합 2개
		for (int j = 4; j <= i; j+=2)
		{
			DP[i] += DP[i-j] * 2; // 연합된 너비로 시작 - 위, 아래 두 개
		}
	}

	cout << DP[N];
	
	return 0;
}

