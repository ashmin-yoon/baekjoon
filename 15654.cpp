#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 8;

int N, M;
vector<int> nums;
bool selected[MAX];
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

	for (int i = 0 ; i < N; i++)
	{
		if (selected[i])
			continue;
		selected[i] = true;
		selectedNums.push_back(nums[i]);

		Solution(count + 1);

		selected[i] = false;
		selectedNums.pop_back();
	}
}


int main()
{
	cin >> N >> M;

	memset(selected, false, sizeof(selected));
	int tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		nums.push_back(tmp);
	}

	// 사용 가능한 숫자 오름차순 정렬
	sort(nums.begin(), nums.end());
	Solution(0);

	return 0;
}
