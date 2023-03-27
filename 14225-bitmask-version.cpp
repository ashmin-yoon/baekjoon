#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 20;

int N;
bool check[100000 * MAX_SIZE + 1];
int ans;

vector<int> S;

bool cmp(const int a, const int b)
{
	if (a < b)
		return true;
	return false;
}

int main() {
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		S.push_back(tmp);
	}

	// 오름차순 정렬
	sort(S.begin(), S.end(), cmp);

	int preCheckingValue = 0;
	int sum = 0;
	bool endFlag = false;
	for (int tc = 0; tc < (1 << N); tc++)
	{
		sum = 0;
		int lastFlagBit = 0;
		for (int i = 0; i < N; i++)
		{
			if (tc & (1 << i))
			{
				sum += S[i];
				lastFlagBit = i;
			}
		}
		check[sum] = true;

		
		// 마지막으로 1 비트를 가지는 자리
		// preCheckingValue ~ S[lastFlagBit] 검사
		//cout << preCheckingValue << " ~ " << S[lastFlagBit] << endl;
		for (int i = preCheckingValue; i < S[lastFlagBit]; i++)
		{
			if (check[i] == false)
			{
				ans = i;
				endFlag = true;
				break;
			}
		}

		if (endFlag)
			break;
		preCheckingValue = S[lastFlagBit];
	}

	// 정답이 없다면 최종값 + 1이 정답
	if (ans == 0)
		ans = sum + 1;
	cout << ans;

	return 0;
}
