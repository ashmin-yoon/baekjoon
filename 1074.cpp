#include <iostream>
using namespace std;

const int MAX_SIZE = 2 << 15;

int N;
bool isFound = false;
int sequence;
int r, c;


void Search(int y, int x, int length) {
	if (isFound || length == 0)
		return;

	// 찾음
	if (r == y && c == x) {
		isFound = true;
		return;
	}

	int divLength = length / 2;
	int numberOfBlock = divLength * divLength;

	if (r < y + divLength && c < x + divLength)  // 좌상
	{
		Search(y, x, divLength); 
	} 
	else if (r < y + divLength && c < x + length)  // 우상
	{
		sequence += numberOfBlock * 1;
		Search(y, x + divLength, divLength);
	} 
	else if (r < (y + length) && c < x + divLength) // 좌하
	{
		sequence += numberOfBlock * 2;
		Search(y + divLength, x, divLength);
	} 
	else  // 우하
	{
		sequence += numberOfBlock * 3;
		Search(y + divLength, x + divLength, divLength);
	}
}

int main() {

	cin >> N >> r >> c;

	Search(0, 0, 2 << N);
	cout << sequence;

	return 0;
}
