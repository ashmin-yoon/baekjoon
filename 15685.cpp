#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE = 101;

int N;
int x, y, d, generation;

int dragonCurve[MAX_SIZE][MAX_SIZE];

const int EAST= 0;
const int NORTH = 1;
const int WEST = 2;
const int SOUTH = 3;

typedef struct Point {
	Point(int y, int x) : y(y), x(x) {}
	int y;
	int x;
}Point;

bool OutOfIndex(int y, int x) {
	if (y < 0 || y >= MAX_SIZE) return true;
	if (x < 0 || x >= MAX_SIZE) return true;
	return false;
}

int CountingAnswer() {
	int answer = 0;
	for (int i = 0; i < MAX_SIZE-1; i++)
	{
		for (int j = 0; j < MAX_SIZE-1; j++)
		{
			if (dragonCurve[i][j] && dragonCurve[i][j+1]
					&& dragonCurve[i+1][j] && dragonCurve[i+1][j+1])
				answer++;
		}
	}

	return answer;
}

void PrintMap() {
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << dragonCurve[i][j];
		}
		cout << "\n";
	}
	cout << endl;
	cout << endl;
	cout << endl;
}

int main() {

	cin >> N;
	
	while(N--) 
	{
		// x, y 시작점
		// d 시작 방향
		// g 세대
		cin >> x >> y;
		cin >> d >> generation;

		dragonCurve[y][x] = 1;

		vector<Point> points;

		// 0세대 만들기
		points.push_back(Point(y, x));
		switch(d)
		{
			case EAST:
				points.push_back(Point(y, x+1));
				break;
			case NORTH:
				points.push_back(Point(y-1, x));
				break;
			case WEST:
				points.push_back(Point(y, x-1));
				break;
			case SOUTH:
				points.push_back(Point(y+1, x));
				break;
		}

		// g세대 만들기
		for (int g = 0; g < generation; g++)
		{
			int tmpCount = points.size();
			Point curr = points.back(); // 현재 위치 기준으로 회전
			for (int i = tmpCount-2; i >= 0; i--)
			{
				int diffY = points[i].y - curr.y;
				int diffX = points[i].x - curr.x;

				Point nextPoint = curr;
				// 현재중심 기준 
				// 제2사분면
				if (diffY <= 0 && diffX < 0)
				{
					nextPoint.y += diffX;
					nextPoint.x -= diffY;
				} 
				// 제1사분면
				else if (diffY < 0 && diffX >= 0)
				{
					nextPoint.y += diffX;
					nextPoint.x -= diffY;
				} 
				// 제3사분면
				else if (diffY > 0 && diffX <= 0)
				{
					nextPoint.y += diffX;
					nextPoint.x -= diffY;
				}
				// 제4사분면	
				else 
				{
					nextPoint.y += diffX;
					nextPoint.x -= diffY;
				}

				// 범위 검사 후 데이터 추가
				if (!OutOfIndex(nextPoint.y, nextPoint.x))
				{
					points.push_back(nextPoint);
				}
			}
		}


		// 데이터 적용
		for (int i = 0; i < points.size(); i++) 
		{
			// 인덱스 범위 검사
			if (OutOfIndex(points[i].y, points[i].x))
				continue;
			dragonCurve[points[i].y][points[i].x] = 1;
		}
	}

	// 정답 수 확인
	cout << CountingAnswer() << endl;


	return 0;
}
