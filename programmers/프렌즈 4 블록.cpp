// https://programmers.co.kr/learn/courses/30/lessons/17679
// 허허 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<string> board) {
	bool end = false;
	int answer = 0;

	while (!end)
	{
		vector<string> check = board;
		end = true;

		for (int r = 0; r < m - 1; ++r)
		{
			for (int c = 0; c < n - 1; ++c)
			{
				// 왼쪽 위 기준으로 체크합니다.
				bool ok = true;
				char ch = board[r][c];
				if (ch == '0' || ch == '1')
					continue;

				ok &= (ch == board[r + 1][c + 0]);
				ok &= (ch == board[r + 1][c + 1]);
				ok &= (ch == board[r + 0][c + 1]);
				if (false == ok)
					continue;

				check[r + 0][c + 0] = '1';
				check[r + 0][c + 1] = '1';
				check[r + 1][c + 0] = '1';
				check[r + 1][c + 1] = '1';
				end = false;
			}
		}

		// 왼쪽 위부터 내려오면서 내립니다.
		for (int r = 0; r < m; ++r)
		{
			for (int c = 0; c < n; ++c)
			{
				if ('1' != check[r + 0][c + 0])
					continue;

				if (r - 1 < 0)
				{
					board[r + 0][c + 0] = '0';
					answer++;
					continue;
				}

				board[r + 0][c + 0] = board[r - 1][c + 0];
				board[r - 1][c + 0] = '0';
				answer++;
			}
		}
	}

	return answer;
}

int main()
{
	cout << solution(4, 5, {"CCBDE", "AAADE", "AAABF", "CCBBF"}) << endl;

	return 0;
}
