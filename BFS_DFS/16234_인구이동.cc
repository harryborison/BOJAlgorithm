#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int N,L,R;
vector<vector<int>> graph;
vector<vector<int>> visit;
int g_idx = 0;
int g_flag = 0;
void bfs(int sy , int sx)
{
    int dy[4] = { 0,0,1,-1 };
    int dx[4] = { 1,-1,0,0 };
    queue<pair<int, int>> q;
    q.push({ sy,sx });
    vector<pair<int, int>> path;
    path.push_back({ sy,sx });
    int t_cnt = 1;
    int t_val = graph[sy][sx];
    visit[sy][sx] = 1;
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (y + dy[i] >= 0 && y + dy[i] < N &&
                x + dx[i] >= 0 && x + dx[i] < N &&
                !visit[y + dy[i]][x + dx[i]] &&
                (abs(graph[y + dy[i]][x + dx[i]] - graph[y][x]) >= L &&
                    abs(graph[y + dy[i]][x + dx[i]] - graph[y][x]) <= R )
                )
            {
                path.push_back({ y + dy[i] ,  x + dx[i] });
                t_val+= graph[y+dy[i]][x+dx[i]];
                q.push({ y + dy[i],x + dx[i] });
                t_cnt++;
                visit[y + dy[i]][x + dx[i]] = 1;
            }
        }
    }
    if (t_cnt >= 2)
    {
        g_flag = 1;
        int ans = t_val / path.size();
        for (int i = 0; i < path.size(); i++)
        {
            graph[path[i].first][path[i].second] = ans;
        }
    }




}
int main(void)
{
    std::cin >> N >> L >> R;
    graph.resize(N);
    visit.resize(N);

    for (int i = 0; i < N; i++)
    {
        visit[i].resize(N);
        graph[i].resize(N);
        for (int j = 0; j < N; j++)
            std::cin >> graph[i][j];
    }
    int cnt = 2001;
    while (cnt--)
    {
        g_flag = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                visit[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visit[i][j])
                {
                    bfs(i, j);
                }
            }
        }
        if (g_flag == 1)
            g_idx++;
    }
    printf("%d", g_idx);
    return 0;
}