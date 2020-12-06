#include <iostream>

using namespace std;

int dp[100001] = {0, };

int fibonacci(int n)
{
	if (n <= 1)
		return n;

	if (dp[n] != 0)
		return dp[n];

	dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	return dp[n];
}

int main()
{
	cout << fibonacci(10) << endl;

	return 0;
}
