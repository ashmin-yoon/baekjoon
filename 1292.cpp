#include <iostream>

using namespace std;

int main()
{
	int n1 = 0, n2 = 0;
	cin >> n1 >> n2;

	int num = 1;
	int count = 0;
	int arr[1001];
	for (int i = 1; i <= 1000; i++)
	{
		arr[i] = num;	
		count++;

		if (num == count)
		{
			num++;
			count = 0;
		}
	}

	int ans = 0;
	for (int i = n1; i <= n2; i++)
	{
		ans += arr[i];
	}

	cout << ans;

	return 0;
}
