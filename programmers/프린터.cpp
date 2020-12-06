// 일반적인 프린터는 인쇄 요청이 들어온 순서대로 인쇄합니다
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	priority_queue<int, vector<int>, less<int>> pq;
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); ++i)
	{
		pq.push(priorities[i]);
		q.push(make_pair(i, priorities[i]));
	}

	int answer = 0;
	while (true)
	{
		pair<int, int> front = q.front();
		q.pop();

		int highest = pq.top();
		if (highest > front.second)
		{
			q.push(front);
			continue;
		}

		answer++;
		pq.pop();

		if (front.first == location)
			return answer;
	}

	return -1;
}

int main()
{
	cout << solution({ 2, 1, 3, 2 }, 2) << endl;

	return 0;
}
