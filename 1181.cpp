#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<string> v;

bool cmp(const string a, const string b)
{
	if (a.size() < b.size())
		return true;
	if (a.size() > b.size())
		return false;

	// length equal
	if(a.compare(b) >= 0)
		return false;
	return true;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cin >> N;

	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
	return 0;
}
