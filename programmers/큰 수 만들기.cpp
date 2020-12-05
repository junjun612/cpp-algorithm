// https://programmers.co.kr/learn/courses/30/lessons/42883
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	for (int i = 0; i < number.length() - 1;)
	{
		if (0 == k)
			break;

		if (number[i] >= number[i + 1])
		{
			i++;
			continue;
		}

		number = number.substr(0, i) + number.substr(i + 1);
		k--;
		i = max(0, i - 1);
	}

	return number.substr(0, number.length() - k);
}
