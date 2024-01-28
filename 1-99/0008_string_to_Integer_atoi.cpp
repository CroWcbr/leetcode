#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        auto tmp = s.begin();
        int znak = 1;
        long int answer = 0;

        while (isspace(*tmp))
            tmp++;

        if (*tmp == '-')
            znak = -1;   
        if (*tmp == '+' || *tmp == '-')
            tmp++;

        if (isdigit(*tmp))
        {
            answer = znak * (*tmp - '0');
            tmp++;
        }
        while (isdigit(*tmp))
        {
            answer = answer * 10 + znak * (*tmp - '0');
            if (answer > INT_MAX)
            {
                answer = INT_MAX;
                break;
            }
            if (answer < INT_MIN)
            {
                answer = INT_MIN;
                break;
            }
            tmp++;
        }

        return answer;
    }
};

int main()
{
    Solution test;

    cout << test.myAtoi("-2147483649") << endl;
}
