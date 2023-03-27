#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int count[10];
	memset(count, 0, sizeof(count));

	string str = to_string(a * b * c);
	for (int i = 0; i < str.size(); i++)
	{
		count[str[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
		cout << count[i] << '\n';


	return 0;
}
