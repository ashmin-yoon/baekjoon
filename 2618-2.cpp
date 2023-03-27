#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int row, col;
vector<pair<int, int> > pathA;
vector<pair<int, int> > pathB;

int num;
int cache[1009][1009];

vector<int> v;


int getMaxDistance(int A, int B)
{	
    // 모든 사건 해결
    if (A == num || B == num)
        return 0;

    int& ret = cache[A][B];

    if (ret != -1)
        return ret;

    ret = 987654321;
    
    // 다음 사건 번호
    int maxLocation = max(A, B) + 1;

    // 경찰차 A 가 다음 사건 해결 시 이동 거리
    int distA = abs(pathA[maxLocation].first - pathA[A].first) +
        abs(pathA[maxLocation].second - pathA[A].second);

    // 경찰차 B 가 다음 사건 해결 시 이동 거리
    int distB = abs(pathB[maxLocation].first - pathB[B].first) +
        abs(pathB[maxLocation].second - pathB[B].second);

    // 경찰차 A 가 다음 사건을 해결하거나, B 가 다음 사건을 해결하거나
    int ret1 = getMaxDistance(maxLocation, B) + distA;
    int ret2 = getMaxDistance(A, maxLocation) + distB;

    return ret = min(ret1, ret2);
}

void reconstruct(int A, int B)
{
    if (A == num || B == num)
        return;

    // 다음 사건 번호
    int maxLocation = max(A, B) + 1;

    int distA = abs(pathA[maxLocation].first - pathA[A].first) +
        abs(pathA[maxLocation].second - pathA[A].second);

    int distB = abs(pathB[maxLocation].first - pathB[B].first) +
        abs(pathB[maxLocation].second - pathB[B].second);

    int ret1 = getMaxDistance(maxLocation, B) + distA;
    int ret2 = getMaxDistance(A, maxLocation) + distB;

    // 현재 상태에서 경찰차 A 가 다음 사건을 해결할 때의 이동 경로가 더 길다면
    if (ret1 > ret2)
    {
        // 경찰차 B 가 다음 사건을 해결
        cout << 2 << endl;
        reconstruct(A, maxLocation);
    }
    else
    {
        cout << 1 << endl;
        reconstruct(maxLocation, B);
    }

}

void solve()
{
    cout << getMaxDistance(0, 0) << endl;
    reconstruct(0, 0);
}

int main()
{
    cin >> row;	col = row;
    cin >> num;
    
    memset(cache, -1, sizeof(cache));

    // 처음 경찰차의 좌표
    pathA.push_back(make_pair(1, 1));
    pathB.push_back(make_pair(row, row));
    
    for (int i = 0; i < num; i++)
    {
        int x, y;	cin >> x >> y;
        pathA.push_back(make_pair(x, y));
        pathB.push_back(make_pair(x, y));
    }
    
    solve();

    return 0;
}
