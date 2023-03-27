#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_SIZE = 11;

int N;
int arr[MAX_SIZE];
int visited[MAX_SIZE];
vector<char> oper;
int MAX = -1e9;
int MIN = +1e9;
int result[MAX_SIZE];


void dfs(int count)
{
	if (count == N-1)
	{
		// 계산
		int value = result[N-1];
		MAX = max(MAX, value);
		MIN = min(MIN, value);
		return;
	}


	for (int i = 1; i < N; i++)
	{
		if (visited[i]) 
			continue;

		visited[i] = true;
		char op = oper[i];
		if (op == '+')
			result[count+1] = result[count] + arr[count+1];
		if (op == '-')
			result[count+1] = result[count] - arr[count+1];
		if (op == '*')
			result[count+1] = result[count] * arr[count+1];
		if (op == '/')
			result[count+1] = result[count] / arr[count+1];
		dfs(count+1);
		visited[i] = false;
	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}


	int plus = 0;
	int minus = 0;
	int multi = 0;
	int	div = 0; 

	cin >> plus;
	cin >> minus;
	cin >> multi;
	cin >> div;

	oper.push_back('0');	// 한 칸 비우기
	for (int i = 0; i < plus; i++)
		oper.push_back('+');
	for (int i = 0; i < minus; i++)
		oper.push_back('-');
	for (int i = 0; i < multi; i++)
		oper.push_back('*');
	for (int i = 0; i < div; i++)
		oper.push_back('/');


	result[0] = arr[0];
	dfs(0);

	cout << MAX << "\n" << MIN << "\n";


	return 0;
}
