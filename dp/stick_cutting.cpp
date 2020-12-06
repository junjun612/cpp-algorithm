#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001] = {0, };

int solution(vector<int> values, int length)
{
	dp[0] = values[0];
	dp[1] = values[1];

	for (int i = 2; i <= length; ++i)
	{
		dp[i] = max(dp[i], values[i]);

		for (int j = 1; j < (i / 2); ++j)
		{
			dp[i] = max(dp[i], dp[j] + dp[i - j]);	
		}
	}

	return dp[length];
}

int main()
{
	cout << solution({0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30}, 7) << endl;

	return 0;
}
