#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// 많은 시간 고민 후
// 논리적 오류(반례) + 너무 많은 코드(비효율) 때문에
// 다른 사람 풀이법 확인 https://excited-hyun.tistory.com/145


int value[26]; 
int N;
vector<pair<int, char> > v;


bool cmp(pair<int, char>& a, pair<int, char>& b) {
	return a.first > b.first;
}

int main() {

	cin >> N;
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			char ch = str[str.size() - 1 - j];
			value[ch - 'A'] += pow(10, j);
		}
	}



	for (int i = 0; i < 26; i++)
	{
		//cout << (char)(i+'A') << " " << value[i] << endl;
		if (value[i] != 0)
			v.push_back(make_pair(value[i], i+'A'));
	}

	sort(v.begin(), v.end(), cmp);

	int ans = 0;
	int num = 9;
	for (int i = 0; i < v.size(); i++)
	{
		//cout << v[i].second << " : " << v[i].first << endl;
		ans += v[i].first * num;
		num--;
	}

	cout << ans << endl;

}
