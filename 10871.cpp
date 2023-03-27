#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	int x;
	
	cin >> n >> x;

	vector<int> v(n);
	int value;

	for (int i = 0; i < n; i++) {
		cin >> value;
		v[i] = value;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		if(v[i] < x)
			cout << v[i] << " ";
	}

	return 0;
}
