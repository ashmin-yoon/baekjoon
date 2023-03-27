#include <iostream>
using namespace std;
const int MAX_SIZE = 600;

int height;
int width;
int x;
int y;
int A[MAX_SIZE][MAX_SIZE];
int B[MAX_SIZE][MAX_SIZE];

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> height >> width;
	cin >> x >> y;

	for (int i = 0; i < height + x; i++)
	{
		for (int j = 0; j < width + y; j++)
		{
			cin >> B[i][j];
		}
	}

	int tmp;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			A[i][j] += B[i][j];
			A[i+x][j+y] -= A[i][j];
		}
	}


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}


	return 0;
}
