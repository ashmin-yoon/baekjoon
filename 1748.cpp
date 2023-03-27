#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int ans = 0;
	int digit = 1;
	string strNum = to_string(n);

	// 자리수 - 1 만큼 먼저 계산
	// ex) 1543 = 9 + 2 * 90 + 3 * 900 + 4 * (543 + 1)
	for (int i = 0; i < strNum.length() - 1; i++) {
		ans += digit * 9 * pow(10, i);
		digit++;
	}

	// 2 자리수 이상
	if (strNum.length() > 1)
	{
		ans += digit * ((n + 1) - pow(10, digit - 1));
	}
	else 
	{
		ans += n;
	}

	cout << ans << endl;

	return 0;
}
