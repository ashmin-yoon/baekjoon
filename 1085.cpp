#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int dist = min(x, y);

	dist = min(dist, w - x);
	dist = min(dist, h - y);

	cout << dist;

	return 0;
}
