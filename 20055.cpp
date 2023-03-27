#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
int N;
int K;
int conveyorBelt[2][MAX_SIZE];
bool robot[MAX_SIZE];

void RotateConveyorBelt() {

	int tmp = conveyorBelt[0][N-1];

	// 위 줄
	for (int i = N-1; i > 0; i--)
	{
		conveyorBelt[0][i] = conveyorBelt[0][i-1];
		robot[i] = robot[i-1];
	}
	conveyorBelt[0][0] = conveyorBelt[1][0];
	robot[0] = false;

	// 아래 줄
	for (int i = 0; i < N - 1; i++)
	{
		conveyorBelt[1][i] = conveyorBelt[1][i+1];
	}
	conveyorBelt[1][N-1] = tmp;
	
}

void MoveRobots() {	

	if (robot[N-1])
	{
		robot[N-1] = false;
	}

	// 로봇 이동
	for (int i = N-2; i >= 0; i--)
	{
		if (robot[i] && !robot[i+1] && conveyorBelt[0][i+1])
		{
			robot[i+1] = robot[i];	// 로봇 이동
			robot[i] = false;
			conveyorBelt[0][i+1]--; // 내구도 감소
															
			// 종료 조건 값 수정
			if (conveyorBelt[0][i+1] == 0) 
				K--;	
		}
	}

}

void PutRobotOrNothing() {
	// 로봇 올리기
	if (conveyorBelt[0][0] > 0)
	{	
		robot[0] = true;
		conveyorBelt[0][0]--;
		if (conveyorBelt[0][0] == 0)
			K--;
	}
	else
		robot[0] = false;

}

void PrintConveyorBelt() {
	cout << "로봇\n";
	for (int i = 0; i < N; i++)
		cout << robot[i] << " ";
	cout << "\n";


	for (int i = 0; i < N; i++)
		cout << conveyorBelt[0][i] << " ";
	cout << "\n";

	for (int i = 0; i < N; i++)
		cout << conveyorBelt[1][i] << " ";
	cout << "\n";
	cout << "\n";

}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	
	cin >> N >> K;
	// 입력
	for (int i = 0; i < N; i++)
	{
		cin >> conveyorBelt[0][i];
	}
	for (int i = N-1; i >= 0; i--)
	{
		cin >> conveyorBelt[1][i];
	}


	int count = 0;
	while(K > 0)
	{
		count++;
		RotateConveyorBelt(); // 1. 벨트 회전
		MoveRobots();					// 2. 로봇 이동
		PutRobotOrNothing();	// 로봇 올림 OR X
		//PrintConveyorBelt();
	}

	cout << count;

	return 0;
}
