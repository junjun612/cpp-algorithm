// https://programmers.co.kr/learn/courses/30/lessons/42627

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> job_t;

int solution(vector<vector<int>> jobs) {
	vector <job_t> job_vector;
	for (const vector<int>& job : jobs)
		job_vector.push_back(make_pair(job[0], job[1]));

	sort(job_vector.begin(), job_vector.end(), [](const job_t& j1, const job_t& j2) {
		return j1.second < j2.second;
	});

	int answer = 0;
	int time = 0;
	while (!job_vector.empty())
	{
		bool is_successed = false;
		for (int i = 0; i < job_vector.size(); ++i)
		{
			// 아직 준비되지 않은 일감입니다.
			if (time < job_vector[i].first)
				continue;

			answer += (time - job_vector[i].first + job_vector[i].second);
			time += job_vector[i].second;
			job_vector.erase(job_vector.begin() + i);
			is_successed = true;
			break;
		}

		if (false == is_successed)
			time++;
	}

	return (answer / jobs.size());
}
