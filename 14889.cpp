#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 20 + 1;

int N;
int S[MAX][MAX];
bool isStartTeam[MAX];
int startTeamMember[MAX];
int linkTeamMember[MAX];
int TotalSum = 0;
int ans = 987654321;


void Solution() {

	int start_i = 0;
	int start_j = 0;

	int link_i = 0;
	int link_j = 0;

	int linkSum = 0;
	int startSum = 0;

	for (int x = 0; x < N/2; x++)
	{
		start_i = startTeamMember[x];	
		link_i = linkTeamMember[x];
		for (int y = x + 1; y < N/2; y++)
		{
			start_j = startTeamMember[y];
			startSum += S[start_i][start_j] + S[start_j][start_i];

			link_j = linkTeamMember[y];
			linkSum += S[link_i][link_j] + S[link_j][link_i];
		}
	}



	ans = min(ans, abs(linkSum - startSum));
	//cout << "start sum = " << startSum << ", link sum = " << linkSum << ", diff = " << linkSum - startSum << endl;
}


void SelectTeam(int idx, int count) {
	if (count == N/2)
	{
		//cout << "팀 선정 완료" << endl;
		for (int i = 0; i < N/2; i++)
			cout << startTeamMember[i] << " ";
		cout << endl;

		
		int linkC = 0;
		for (int i = 1; i <= N; i++) {
			if(isStartTeam[i] == false)
			{
				linkTeamMember[linkC++] = i;
			}
		}
		// 여기서 계산
		Solution();

		return;
	}

	for (int i = idx; i < N; i++) {
		isStartTeam[i] = true;
		startTeamMember[count] = i;
		SelectTeam(i + 1, count + 1);
		isStartTeam[i] = false;
	}
}

int main()
{
	cin >> N;
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> S[i][j];
		}
	}

	SelectTeam(1, 0);
	cout << ans << endl;

	return 0;
}
