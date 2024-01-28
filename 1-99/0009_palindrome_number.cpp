#include <stdint.h>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
          return false;
        unsigned int tmp = 0;
        for (int i = x; i != 0; i /= 10)
            tmp = tmp * 10 + i % 10;
        if (tmp == x)
            return true;
        else
            return false;
    }
};

int main()
{
    Solution test;

    cout << test.isPalindrome(1211) << endl;
}
