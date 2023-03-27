#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
	int count;
	cin >> count;

	int num;
	vector<int> v;
	while(count--)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	cout << v.front() * v.back();
	return 0;
}
