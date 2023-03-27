#include <iostream>
#include <vector>
using namespace std;

int cnt[26];

int main()
{

	string str;
	while(true)
	{
		cin >> str;
		if (cin.eof())
			break;
		for (int i = 0; i < str.size(); i++)
		{
			cnt[str[i] - 'a']++;
		}
	}
	
	int max = 0;
	vector<char> ans;
	for (int i = 0; i < 26; i++)
	{
		cout << cnt[i] << " ";
		if (max < cnt[i])
		{
			ans.clear();
			max = cnt[i];
		}

		if (cnt[i] == max)
		{
			ans.push_back(i + 'a');
		}
	}

	cout << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
	}
	
	return 0;
}
