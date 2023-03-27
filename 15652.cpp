#include <iostream>
#include <string>

using namespace std;

int N, M;
string str;

void Solution(int pick, int count)
{
	if (count == M)
	{
		cout << str << "\n";
		return;
	}

	for (int i = pick; i <= N; i++)
	{
		str += to_string(i);
		str += " ";
		Solution(i, count + 1);
		str = str.substr(0, str.size() - 2);
	}
}

int main()
{
	cin >> N >> M;
	Solution(1, 0);
	return 0;
}
