#include <iostream>
#include <vector>

using namespace std;

int N;
int K;
int ans;

bool visited[26];
vector<string> word;
// 헷갈리고 어려웠음


bool isMatching(string &str) {

	char ch;
	for (int i = 0; i < str.size(); i++)
	{
		ch = str[i];
		if (!visited[ch - 'a']) {
			return false;
		}
	}

	return true;
}


int GetMatchingCount() {
	int cnt = 0;

	for (int i = 0; i < word.size(); i++)
	{
		if (isMatching(word[i]))
			cnt++;
	}
	return cnt;
}



void Solution(int count, int index) {
	if (K < 5) 
	{
		cout << 0;
		exit(0);
	}
	
	if (K == 26)
	{
		cout << N;
		exit(0);
	}

	if (count == K - 5)
	{
		int cnt = GetMatchingCount();
		ans = max(ans, cnt);
		return;
	}


	for (int i = index; i < 26; i++)
	{	
		if (visited[i]) continue;
		visited[i] = true;
		Solution(count+1, i+1);
		visited[i] = false;
	}

}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> K;


	string str;
	for (int i = 0; i < N; i++)
	{
		int n = 0;
		cin >> str;
		word.push_back(str);
	}

	visited['a' - 'a'] = visited['c' - 'a'] = visited['i' - 'a'] = true;
	visited['n' - 'a'] = visited['t'-'a'] = true;

	
	Solution(0, 0);
	cout << ans;

	return 0;
}
