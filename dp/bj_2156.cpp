#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001] = {0, };

int solution(vector<int> numbers)
{
	dp[0] = numbers[0];
	dp[1] = numbers[0] + numbers[1];

	for (int i = 2; i < numbers.size(); ++i)
	{
		const int a1 = dp[i - 1];								// OOX
		const int a2 = numbers[i] + dp[i - 2];					// OXO
		const int a3 = numbers[i] + numbers[i -1] + dp[i - 3];	// XOO
		dp[i] = max({ a1, a2, a3 });
	}

	return dp[numbers.size() - 1];
}

int main()
{
	cout << solution({100, 400, 2, 1, 4, 200}) << endl;

	return 0;
}
