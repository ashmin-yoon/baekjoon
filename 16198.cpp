#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 11;

int N;
int weight[MAX_SIZE];
bool visited[MAX_SIZE];
int ans;

int getPreWeight(int index) {
	int rev = -1;
	for (int i = index-1; i > 0; i--)
	{
		if (!visited[i])
		{	
			rev = weight[i];
			break;
		}
	}
	return rev;
}

int getNextWeight(int index) {
	int rev = -1;
	for (int i = index+1; i <= N; i++)
	{
		if (!visited[i])
		{	
			rev = weight[i];
			break;
		}
	}
	return rev;
}

void dfs(int count, int energy) {
	if (count == N-2)
	{
		ans = max(ans, energy);
	}

	for (int i = 2; i < N; i++)
	{
		if (visited[i]) continue;
		int preWeight = getPreWeight(i);
		int nextWeight = getNextWeight(i);

		visited[i] = true;
		dfs(count+1, energy + preWeight * nextWeight);
		visited[i] = false;
	}
}

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> weight[i];
	}


	// [1, N] 범위 탐색
	dfs(0, 0);
	cout << ans << "\n";


	return 0;
}
