#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 20;
const int INF = 987654321;

int N;
int M;
char board[MAX_SIZE][MAX_SIZE];
int ans = INF;
int selected_direction[11];
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];

const char COIN = 'o';
const char SPACE = ' ';
const char WALL = '#';

enum Direction {
	LEFT,
	RIGHT,
	UP,
	DOWN
};

bool outOfIndex(pair<int, int>& p) {
	if (p.first < 0 || p.first >= N) return true;
	if (p.second < 0 || p.second >= M) return true;
	return false;
}


int getOutCount(pair<int, int>& coin1, pair<int, int>& coin2) {
	int out_count = 0;

	if (outOfIndex(coin1))
		out_count++;
	if (outOfIndex(coin2))
		out_count++;

	return out_count;
}

void moveCoins(int direction, pair<int, int>& coin1, pair<int, int>& coin2) {
	pair<int, int> next_coin1 = coin1;
	pair<int, int> next_coin2 = coin2;

	switch(direction)
	{
		case LEFT:
			next_coin1.second--;
			next_coin2.second--;
			break;
		case RIGHT:
			next_coin1.second++;
			next_coin2.second++;
			break;
		case UP:
			next_coin1.first--;
			next_coin2.first--;
			break;
		case DOWN:
			next_coin1.first++;
			next_coin2.first++;
			break;
	}

	// coin1
	if (outOfIndex(next_coin1)) {
		coin1 = next_coin1;	
	} else if (board[next_coin1.first][next_coin1.second] != WALL) {
		coin1 = next_coin1;
	}
	
	// coin2
	if (outOfIndex(next_coin2)) {
		coin2 = next_coin2;
	}else if (board[next_coin2.first][next_coin2.second] != WALL) {
		coin2 = next_coin2;
	}

}
	

void dfs(int count, pair<int, int> coin1, pair<int, int> coin2) {
	if (count > ans || count > 10) {
		return;
	}

	int out_count = getOutCount(coin1, coin2);
	if (out_count == 1)
	{
		ans = min(ans, count);
//		for (int i = 0; i < count; i++)
//		{
//			cout << selected_direction[i] << " ";
//		}
//		cout << "       " << coin1.first << " " << coin1.second << "      " << coin2.first << " " << coin2.second << "\n";
//
		return;
	}

	if (out_count == 2)
	{
		return;
	}


	// 이동
	for (int i = 0; i < 4; i++)
	{
		pair<int, int> next_coin1 = coin1;
		pair<int, int> next_coin2 = coin2;
		moveCoins(i, next_coin1, next_coin2);

		selected_direction[count] = i;

		if (!outOfIndex(next_coin1) && !outOfIndex(next_coin2))
		{
			if(visited[next_coin1.first][next_coin1.second][next_coin2.first][next_coin2.second])
				continue;
			visited[next_coin1.first][next_coin1.second][next_coin2.first][next_coin2.second] = true;
		}
		dfs(count + 1, next_coin1, next_coin2);


		if (!outOfIndex(next_coin1) && !outOfIndex(next_coin2))
			visited[next_coin1.first][next_coin1.second][next_coin2.first][next_coin2.second] = false;
	}

}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	vector<pair<int, int> > coins;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			board[i][j] = str[j];
			if (board[i][j] == COIN)
			{
				coins.push_back(make_pair(i, j));
			}
		}
	}


	dfs(0, coins[0], coins[1]);

	if (ans > 10)
		ans = -1;
	cout << ans;



	return 0;
}
