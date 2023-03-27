#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> nums;
vector<int> selectedNums;


void Solution(int pickIdx, int count)
{
	if (count == M)
	{
		for (int i = 0; i < count; i++)
		{
			cout << selectedNums[i] << " ";
		}
		cout << "\n";
		return;
	}


	for (int i = pickIdx; i < N; i++)
	{
		selectedNums.push_back(nums[i]);
		Solution(i, count + 1);	
		selectedNums.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());
	Solution(0, 0);

	return 0;
}
