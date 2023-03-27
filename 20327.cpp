#include <iostream>
using namespace std;
const int MAX_SIZE = 1 << 7;

int arr[MAX_SIZE][MAX_SIZE];
int tmpArr[MAX_SIZE][MAX_SIZE];
int N;
int R;
int CMD_Arr[1000];
int L_Arr[1000];
int ROWS;
int COLS;
int mROWS;
int mCOLS;

int rCount;
int cCount;

void Input()
{
	cin >> N >> R;

	ROWS = COLS = 1 << N;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cin >> arr[i][j];
		}
	}

	// k번 연산, 단계 l
	for (int i = 0; i < R; i++)
	{
		cin >> CMD_Arr[i];
		cin >> L_Arr[i];
	}
}

// 각 부분 배열 상하 반전
void CMD1() 
{

	for (int i = 0; i < rCount; i++)
	{
		for (int j = 0; j < cCount; j++)
		{
			int startR = i * mROWS;
			int startC = j * mCOLS;
			int endR = startR + mROWS - 1;
			int endC = startC + mCOLS - 1;

			for (int mr = 0; mr < mROWS / 2; mr++)
			{
				for (int mc = 0; mc < mCOLS; mc++)
				{
					int col = mc + startC;
					int tmp = arr[startR + mr][col];
					arr[startR + mr][col] =	arr[endR - mr][col];
					arr[endR - mr][col] = tmp;
				}
			}
		}
	}
	

}

// 각 부분 좌우 반전
void CMD2()
{
	for (int i = 0; i < rCount; i++)
	{
		for (int j = 0; j < cCount; j++)
		{
			int startR = i * mROWS;
			int startC = j * mCOLS;
			int endR = startR + mROWS - 1;
			int endC = startC + mCOLS - 1;

			for (int mr = 0; mr < mROWS; mr++)
			{
				for (int mc = 0; mc < mCOLS / 2; mc++)
				{
					int row = mr + startR;
					int tmp = arr[row][startC + mc];
					arr[row][startC + mc] =	arr[row][endC - mc];
					arr[row][endC - mc] = tmp;
				}
			}
		}
	}
}

// 각 부분 오른쪽으로 90도 회전
void CMD3() {

	for (int i = 0; i < rCount; i++)
	{
		for (int j = 0; j < cCount; j++)
		{
			int startR = i * mROWS;
			int startC = j * mCOLS;
			int endR = startR + mROWS - 1;
			int endC = startC + mCOLS - 1;

			for (int mr = 0; mr < mROWS; mr++)
			{
				for (int mc = 0; mc < mCOLS; mc++)
				{
					int row = mr + startR;
					int col = mc + startC;
					tmpArr[mc + startR][mCOLS-1-mr + startC] = arr[row][col];
				}
			}
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = tmpArr[i][j];
		}
	}

}


// 각 부분 왼쪽으로 90도 회전
void CMD4() {
	for (int i = 0; i < rCount; i++)
	{
		for (int j = 0; j < cCount; j++)
		{
			int startR = i * mROWS;
			int startC = j * mCOLS;
			int endR = startR + mROWS - 1;
			int endC = startC + mCOLS - 1;

			for (int mr = 0; mr < mROWS; mr++)
			{
				for (int mc = 0; mc < mCOLS; mc++)
				{
					int row = mr + startR;
					int col = mc + startC;
					tmpArr[mROWS-1-mc + startR][mr + startC] = arr[row][col];
				}
			}
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = tmpArr[i][j];
		}
	}

}

// 부분 배열을 한 칸으로 보고 상하 반전
void CMD5() {
	for (int i = 0; i < rCount / 2; i++)
	{
		for (int j = 0; j < cCount; j++)
		{
			int startR = i * mROWS;
			int startC = j * mCOLS;

			int targetR = (rCount-1-i) * mROWS;
			for (int mr = 0; mr < mROWS; mr++)
			{
				for (int mc = 0; mc < mCOLS; mc++)
				{
					int tmp = arr[startR + mr][startC + mc];
					arr[startR + mr][startC + mc] = arr[targetR + mr][startC + mc];
					arr[targetR + mr][startC + mc] = tmp;
				}
			}
	
		}
	}

}

// 부분 배열을 한 칸으로 보고 좌우 반전
void CMD6() {
	for (int i = 0; i < rCount; i++)
	{
		for (int j = 0; j < cCount/2; j++)
		{
			int startR = i * mROWS;
			int startC = j * mCOLS;

			int targetC = (cCount-1-j) * mCOLS;
			for (int mr = 0; mr < mROWS; mr++)
			{
				for (int mc = 0; mc < mCOLS; mc++)
				{
					int tmp = arr[startR + mr][startC + mc];
					arr[startR + mr][startC + mc] = arr[startR + mr][targetC + mc];
					arr[startR + mr][targetC + mc] = tmp;
				}
			}
	
		}
	}

}


// 한 칸으로 보고 오른쪽 90도
void CMD7() {
	for (int i = 0; i < rCount; i++)
	{
		for (int j = 0; j < cCount; j++)
		{
			int startR = i * mROWS;
			int startC = j * mCOLS;

			int targetR = j * mROWS;
			int targetC = (cCount - 1 - i) * mCOLS;
			for (int mr = 0; mr < mROWS; mr++)
			{
				for (int mc = 0; mc < mCOLS; mc++)
				{
					tmpArr[targetR + mr][targetC + mc] = arr[startR+mr][startC+mc];
				}
			}
	
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = tmpArr[i][j];
		}
	}


}


// 한 칸으로 보고 왼쪽 90도
void CMD8() {
	for (int i = 0; i < rCount; i++)
	{
		for (int j = 0; j < cCount; j++)
		{
			int startR = i * mROWS;
			int startC = j * mCOLS;

			int targetR = (rCount - 1 - j) * mROWS;
			int targetC = i * mCOLS;
			for (int mr = 0; mr < mROWS; mr++)
			{
				for (int mc = 0; mc < mCOLS; mc++)
				{
					tmpArr[targetR + mr][targetC + mc] = arr[startR+mr][startC+mc];
				}
			}
	
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = tmpArr[i][j];
		}
	}



}

void Execute(int cmd, int level)
{
	mROWS = mCOLS = 1 << level;

	rCount = ROWS/mROWS;
	cCount = COLS/mCOLS;

	switch(cmd)
	{
		case 1:
			CMD1();
			break;
		case 2:
			CMD2();
			break;
		case 3:
			CMD3();
			break;
		case 4:
			CMD4();
			break;
		case 5:
			CMD5();
			break;
		case 6:
			CMD6();
			break;
		case 7:
			CMD7();
			break;
		case 8:
			CMD8();
			break;
	}
}

void PrintMap()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	Input();
	for (int i = 0; i < R; i++)
	{
		Execute(CMD_Arr[i], L_Arr[i]);
	}
	
	PrintMap();
	return 0;
}
