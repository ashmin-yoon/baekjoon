#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> nums;
vector<int> selectedNums;

void Solution(int count)
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

	for (int i = 0; i < N; i++)
	{
		selectedNums.push_back(nums[i]);
		Solution(count+1);
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
	Solution(0);

	return 0;
}
