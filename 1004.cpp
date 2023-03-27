#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct {
	int x;
	int y;
}Point;

class Circle{
	public:
		Circle();
		Circle(int x, int y, int r) : x(x), y(y), r(r) {};

		// 편의성을 위해 전체 public
		int x;
		int y;
		int r;
};


int FindCountInCircle(Point& point, vector<Circle>& v) {
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		// 두 점 사이의 거리, 루트는 씌우지 않았음
		int distance_to_the_2 = pow(point.x - v[i].x, 2) + pow(point.y - v[i].y, 2);
		if (distance_to_the_2 < pow(v[i].r, 2))
			count++;
	}
	return count;
}

int FindCommonCountInCircle(Point& st, Point& desti, vector<Circle>& v) {
	// 만약 공통으로 포함되어 있다면 count 되면 안됨
	// 정답 = 출발지 포함 원 개수 + 도착지 포함 원 개수 - 공통 포함하는 원 개수
	int count = 0;

	for (int i = 0; i < v.size(); i++) {
		// 두 점 사이의 거리, 루트는 씌우지 않았음
		int st_distance_to_the_2 = pow(st.x - v[i].x, 2) + pow(st.y - v[i].y, 2);
		int desti_distance_to_the_2 = pow(desti.x - v[i].x, 2) + pow(desti.y - v[i].y, 2);
		if ( (st_distance_to_the_2 < pow(v[i].r, 2)) && (desti_distance_to_the_2 < pow(v[i].r, 2)) )
			count++;
	}
	return count;



}

int main() { 
	int test_case;
	cin >> test_case;

	Point starting_p; 
	Point destination_p;
	int space_count;
	vector<Circle> v;
	vector<int> answer;

	for (int i = 0; i < test_case; i++) {
		v.clear();
		cin >> starting_p.x >> starting_p.y;
		cin >> destination_p.x >> destination_p.y;
		cin >> space_count;

		for (int j = 0; j < space_count; j++) {
			int tx, ty, tr;
			cin >> tx >> ty >> tr;
			v.push_back(Circle(tx, ty, tr));
		}
		int count = 0;
		count += FindCountInCircle(starting_p, v);
		count += FindCountInCircle(destination_p, v);
		count -= 2 * FindCommonCountInCircle(starting_p, destination_p, v); // 제외 시켜주려면 2번 빼줘야함
		answer.push_back(count);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}

	return 0;
}
