#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 8;

int N, M;
vector<int> nums;
vector<int> selectedNums;

void Solution(int pickIdx, int count)
{
	if (count == M)
	{
		for (int i = 0; i < selectedNums.size(); i++)
		{
			cout << selectedNums[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = pickIdx; i < N; i++) {
		selectedNums.push_back(nums[i]);
		Solution(i + 1, count + 1);
		selectedNums.pop_back();
	}
}

int main()
{
	cin >> N >> M;

	int tmp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());
	Solution(0, 0);

	return 0;
}

