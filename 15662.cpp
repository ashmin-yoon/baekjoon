#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 1001;

int T;
int K;
bool gear[MAX_SIZE][8];
int ans;

enum Direction {
	COUNTER_CLOCKWISE = -1,
	NONE,
	CLOCKWISE = 1
};

const int LEFT = 6;
const int RIGHT = 2;

void RotateGears(vector<Direction>& dirVec)
{
	for (int i = 1; i < dirVec.size(); i++)
	{
		if (dirVec[i] == CLOCKWISE)
		{
			int last = gear[i][7];
			for (int j = 8 - 1; j > 0; j--)
			{
				gear[i][j] = gear[i][j-1];
			}
			gear[i][0] = last;
		}
		if (dirVec[i] == COUNTER_CLOCKWISE)
		{
			int first = gear[i][0];
			for (int j = 0; j < 8 - 1; j++)
			{
				gear[i][j] = gear[i][j+1];
			}
			gear[i][7] = first;
		}
	}
}

void Rotate(int gearNumber, Direction direction) {
	vector<Direction> dirVec(T+1, NONE);
	dirVec[gearNumber] = direction;

	// 뒤 기어들
	for (int cur = gearNumber + 1; cur <= T; cur++)
	{
		int pre = cur - 1;
		// 회전해야 할 때
		if (gear[pre][RIGHT] != gear[cur][LEFT])
		{
			if (dirVec[pre] == CLOCKWISE)
				dirVec[cur] = COUNTER_CLOCKWISE;
			if (dirVec[pre] == COUNTER_CLOCKWISE)
				dirVec[cur] = CLOCKWISE;
		}
	}

	// 앞 기어들
	for (int cur = gearNumber - 1; cur > 0; cur--)
	{
		int next = cur + 1;
		// 회전해야 할 때
		if (gear[next][LEFT] != gear[cur][RIGHT])
		{
			if (dirVec[next] == CLOCKWISE)
				dirVec[cur] = COUNTER_CLOCKWISE;
			if (dirVec[next] == COUNTER_CLOCKWISE)
				dirVec[cur] = CLOCKWISE;
		}
	}

	RotateGears(dirVec);
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> T;

	for (int i = 1; i <= T; i++) 
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '1')
				gear[i][j] = true;
		}
	}

	cin >> K;
	while(K--)
	{
		int gearNumber;
		int intDir;
		cin >> gearNumber >> intDir;
		Direction direction;
		direction = static_cast<Direction>(intDir);
		

		Rotate(gearNumber, direction);
	}

	for (int i = 1; i <= T; i++)
	{
		if (gear[i][0])
			ans++;
	}

	cout << ans << "\n";
	return 0;
}
