#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long int answer = 0;
        long int tmp = x;
        bool znak = true;

        if (x < 0)
        {
            znak = false;
            tmp *= -1;
        }

        while (tmp)
        {
            answer = answer * 10 + tmp % 10;
            tmp /= 10;
        }

        if (answer > INT_MAX)
            answer = 0;

        return znak ? answer : -answer;
    }
};

int main()
{
    Solution test;

    cout << test.reverse(-2147483648) << endl;
}
