#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[20001];
int num = -1, dis = 0, cnt = 0;
int d[20001];

void dijkstra(int start)
{
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    //가까운 순서대로 처리하기 위해 큐 사용

    while (!pq.empty())
    {
        //짧은 것이 먼저 오도록 음수화 함.
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        //최단 거리가 아닌 경우 스킵
        if (d[current] < distance)
            continue;
        for (int i = 0; i < v[current].size(); i++)
        {
            //선택된 노드의 인접노드
            int next = v[current][i];
            //선택된 노드를 인접 노드를 거쳐서 가는 비용
            int nextDistance = 1 + distance;
            //기존의 최소 비용보다 더 저렴하다면 교체
            if (nextDistance < d[next])
            {
                d[next] = nextDistance;
                dis = max(dis, nextDistance);
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}

int main(int argc, const char *argv[])
{
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int ans = 2147000000;
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i <= N; i++)
    {
        d[i] = 2147000000;
    }
    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }
    dijkstra(1);
    for (int i = 1; i <= N; i++)
    {
        if (dis == d[i])
        {
            if (num == -1)
                num = i;
            cnt++;
        }
    }
    cout << num << " " << dis << " " << cnt << "\n";

    return 0;
}