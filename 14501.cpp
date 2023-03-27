#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 15;

int N;
int T[MAX] = {0};
int P[MAX] = {0};
int ans = 0;

void BruteForce(int day, int sum)
{
	if (day > N)
	{
		return;
	}
	
	ans = max(ans, sum);
	
	for (int i = day; i < N; i++)
	{
		BruteForce(i + T[i], sum + P[i]);
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> T[i] >> P[i];
	}

	
	BruteForce(0, 0);
	cout << ans << endl;

	return 0;
}
