#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        string answer(s.length(), ' ');

        int count = 0;
        int delta = numRows * 2 - 2;
        for (int i = 0; i < numRows; ++i)
        {
            for (int ii = 0; i + ii * delta < s.length(); ii++)
            {
                answer[count++] = s[i + ii * delta];
                if (i > 0 && i < numRows - 1)
                    if (i + (ii + 1) * delta - i * 2 < s.length())
                        answer[count++] = s[i + (ii + 1) * delta - i * 2];
            }
        }

        return answer;
    }
};

int main()
{
    Solution test;

    std::cout << test.convert("PAYPALISHIRING", 3) << std::endl;
}
