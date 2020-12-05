// https://programmers.co.kr/learn/courses/30/lessons/43165

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(const vector<int>& numbers, const int n, const int result, const int target, int& answer) {
	if (numbers.size() <= n)
	{
		answer += (target == result) ? 1 : 0;
		return;
	}

	dfs(numbers, n + 1, result + numbers[n], target, answer);
	dfs(numbers, n + 1, result - numbers[n], target, answer);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	dfs(numbers, 0, 0, target, answer);
	return answer;
}

int main() {
	cout << solution({1, 1, 1, 1, 1}, 3) << endl;
	return 0;
}
