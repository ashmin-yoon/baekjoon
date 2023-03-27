#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10001;


int N;
vector<int> v;
bool checked[MAX];

vector<int> ans;

int main()
{
	cin >> N;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	
	
	int index = -1;
	for (int i = v.size() - 1; i > 0; i--)
	{
		if (v[i-1] > v[i]) {
			index = i - 1;	
			break;
		}
	}

	// 불가능
	if (index == -1)
	{
		cout << -1;
		return 0;
	}

	// 가능
	int value = 0;
	for (int i = 0; i < index; i++) {
		value = v[i];
		checked[value] = true;
		ans.push_back(value);
	}

	sort(v.begin() + index + 1, v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout <<endl;
	ans.push_back(v[index + 1]);
	checked[v[index + 1]] = true;
	
	// 내림 차순 정렬
	for (int i = N; i > 0; i--) {
		if (checked[i]) continue;
		ans.push_back(i);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}


	return 0;
}
