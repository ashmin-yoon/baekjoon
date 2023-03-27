#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 100001;

int N;
queue<int> path;
vector<int> adj[MAX_SIZE];
bool visited[MAX_SIZE];
int moveable_count[MAX_SIZE];

void FastIO() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
}

void Input() 
{

	cin >> N;

	// 간선 연결
	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		moveable_count[u]++;
		moveable_count[v]++;
	}

	// 방문 경로
	for (int i = 0; i < N; i++)
	{
		cin >> v;
		path.push(v);
	}

}

// 이동 가능한 위치 수
int GetNumberOfMoveableLocations(int vertex) {
	int count = 0;

	for (int next : adj[vertex])
	{
		if (!visited[next])
			count++;
	}

	return count;
}


bool CheckMoveVertexToNext(int vertex, int next)
{


	int left = 0;
	int right = adj[vertex].size() - 1;

	while(left <= right)
	{
		int mid = (left + right) / 2;

		if (next > adj[vertex][mid])
		{
			left = mid + 1;
		}
		else if (adj[vertex][mid] == next)
		{
			return true;
		}
		else
		{
			right = mid - 1;			
		}
	}


	// 단순 순차 반복 - 시간초과의 원인으로 판단됨
//	for (int adj_vertex : adj[vertex])
//	{
//		if (!visited[adj_vertex] && adj_vertex == next)
//			return true;
//	}

	return false;
}

void PrintStackAndInfo(vector<int>& stack, int vertex)
{
	cout << endl;
	for (int item : stack)
	{
		cout << item << " ";
	}
	cout << "<-- top" << endl;
	//cout << "이동 가능 경로 개수 " << GetNumberOfMoveableLocations(vertex) << endl;
	cout << "이동 가능 경로 개수 " << moveable_count[vertex] << endl;
	cout << "path.size() = " << path.size() << endl;
	cout << endl;
}



bool VerifyDFS()
{
	// 시간 초과로 벡터 수정
	vector<int> stack(MAX_SIZE);

	stack[0] = 1; // 시작 1 고정

	int index = 0;

	while(index >= 0)
	{
		int vertex = stack[index];
		//PrintStackAndInfo(stack, vertex);

		// 방문 하지 않은 정점 검즘
		if (!visited[vertex]) 
		{
			if (vertex != path.front())
				return false;
			path.pop();

			// 이동 가능 개수 감소
			for (int i = 0; i < adj[vertex].size(); i++)
			{
				moveable_count[adj[vertex][i]]--;
			}
		}
		visited[vertex] = true;


		// 경로 없음
		if (path.empty() || moveable_count[vertex] == 0)
		{
			index--; // pop
			continue;
		}

		// vertex -> next 로 갈 수 있는지
		int next = path.front();
		if (!CheckMoveVertexToNext(vertex, next))
		{
			return false;
		}
			
		index++;
		stack[index] = next; // push
	}

	// path 남아 있으면 실패
	if (!path.empty())
		return false;

	return true;
}


void SortAdj() 
{
	for (int i = 1; i <= N; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}
}

int main() {

	FastIO();
	Input();	
	SortAdj(); // 인접 정렬

	// 스택으로 검증하기
	if (VerifyDFS())
		cout << true << endl;	
	else 
		cout << false << endl;	


	return 0;
}
