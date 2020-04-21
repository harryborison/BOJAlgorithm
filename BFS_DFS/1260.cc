#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <queue>
int** graph;
int N, M, V;
int* visit_arr;

using namespace std;
int gcnt = 0;
std::stack<int> visit;
std::queue<int> visit_q;
int *sunso;

void dfs(int t)
{
	//V = start
	if (visit_arr[t] == 0)
	{
		
		sunso[gcnt++] = t;
		visit_arr[t] = 1; // V 만났고

	}
	for (int k = 1; k <= N; k++)
	{
		if ( graph[t][k] != 0 && visit_arr[k] ==0 ) // 최대값 탐사중 서치 해봐야 하는 경우 발생시
		{
		//	printf(" %d %d ", t,k);

			visit.push(t); // V 푸쉬
			
			dfs(k);
		}
	}

	/// 연락할 경우가 없는 경우
	if (visit.empty())
	{
		return;
	}
	else
	{
		int w = visit.top();
		visit.pop();
		dfs(w);
	}
}

void bfs(int t)
{

	for (int k = 1; k <= N; k++)
	{
		if (graph[t][k] != 0 && visit_arr[k] == 0) // 최대값 탐사중 서치 해봐야 하는 경우 발생시
		{
			visit_q.push(k); // V 푸쉬
			//printf("-%d-", k);
			visit_arr[k] = 1; // 만남처리
			sunso[gcnt++] = k;
		}

	}

	if (visit_q.empty())
	{
		return;
	}
	else
	{
		int w = visit_q.front();
		visit_q.pop();
		bfs(w);
	}
	/// 연락할 경우가 없는 경우
	











}




int main(void)
{
	std::cin >> N;
	std::cin >> M;
	std::cin >> V;
	sunso = (int*)malloc(sizeof(int) * (N));
	graph = (int**)malloc(sizeof(int*) * (N+1));
	visit_arr= (int*)malloc(sizeof(int) * (N + 1));
	for (int i =0; i < N+1; i++)
	{
		visit_arr[i] = 0;
		graph[i] = (int*)malloc(sizeof(int) *( N+1));
	}
	
	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			graph[i][j] = 0;
		}

	}
	
	for (int k = 0; k < M; k++)
	{
		int a, b;
		std::cin >> a;
		std::cin >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	dfs(V);
	for (int i=0 ;i < gcnt ;i++)
	{
		printf("%d ", sunso[i]);
	}
	gcnt = 0;
	for (int i = 0; i < N+1; i++)
	{
		visit_arr[i] = 0;
	}

	for (int i = 0; i < N ; i++)
	{
		sunso[i] = 0;
	}
	visit_arr[V] = 1;
	sunso[0] = V;
	gcnt++;
	printf("\n");
	bfs(V);
	for (int i = 0; i < gcnt; i++)
	{
		printf("%d ", sunso[i]);
	}
	




	return 0;
}