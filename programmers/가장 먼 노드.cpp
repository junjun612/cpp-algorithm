// https://programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(int start, const vector<vector<int>>& graph, vector<int>& length_list)
{
	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		const int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); ++i)
		{
			int next = graph[cur][i];
			if (length_list[next] <= length_list[cur] + 1)
				continue;

			length_list[next] = length_list[cur] + 1;
			q.push(graph[cur][i]);
		}
	}
}

void dfs(int start, const vector<vector<int>>& graph, vector<int>& length_list)
{
	for (int i = 0; i < graph[start].size(); ++i)
	{
        	// 해당 노드에 접근할 수 있는 최소 값인 경우 다시 계산합니다.
		int next = graph[start][i];
		if (length_list[next] <= length_list[start] + 1)
			continue;

		length_list[next] = length_list[start] + 1;
		dfs(next, graph, length_list);
	}
}

int solution(int n, vector<vector<int>> edge) {
	// Graph 형태로 변경
	vector<vector<int>> graph;
	graph.resize(n);

	for (int i = 0; i < edge.size(); ++i)
	{
		graph[edge[i][0] - 1].push_back(edge[i][1] - 1);
		graph[edge[i][1] - 1].push_back(edge[i][0] - 1);
	}

    	// dfs로 돌면서 확인
	vector<int> length_list;
	for (int i = 0; i < n; ++i)
		length_list.push_back(n);
	
	length_list[0] = 0;
	bfs(0, graph, length_list);

    	// 몇개가 최대 길이인지 확인후 반환
	sort(length_list.begin(), length_list.end(), greater<int>());
	for (int i = 0; i < length_list.size(); ++i)
	{
		if (length_list[0] <= length_list[i])
			continue;
		
		return i;
	}

	return n;
}
