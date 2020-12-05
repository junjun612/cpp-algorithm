// https://programmers.co.kr/learn/courses/30/lessons/67256
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> Vector;
const Vector g_NumberLocation[] = { 
    {1, 3}, 
    {0, 0}, {1, 0}, {2, 0}, 
    {0, 1}, {1, 1}, {2, 1},
    {0, 2}, {1, 2}, {2, 2},
    {0, 3}, {2, 3}
};

int g_CurrentLeftHand = 10;
int g_CurrentRightHand = 11;

int GetDistance(const int number1, const int number2)
{
    const Vector& v1 = g_NumberLocation[number1];
    const Vector& v2 = g_NumberLocation[number2];
    
    return abs(v1.first - v2.first) + abs(v1.second - v2.second);
}

char FindPressingHand(const int number, const string& handType)
{
    if (1 == number || 4 == number || 7 == number)
        return 'L';
    
    if (3 == number || 6 == number || 9 == number)
        return 'R';

    const int LeftHandDistance = GetDistance(g_CurrentLeftHand, number);
    const int RightHandDistance = GetDistance(g_CurrentRightHand, number);
    if (LeftHandDistance > RightHandDistance)
        return 'R';
    
    if (RightHandDistance > LeftHandDistance)
        return 'L';
    
    return (handType == "left") ? 'L' : 'R';
}

char PressButton(const int number, const string& handType)
{
    char PressingHand = FindPressingHand(number, handType);
    if (PressingHand == 'L')
        g_CurrentLeftHand = number;
    else
        g_CurrentRightHand = number;
    
    return PressingHand;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    for (const int number : numbers)
    {
        char ch = PressButton(number, hand);
        answer += ch;
    }
    
    return answer;
}
