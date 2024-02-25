#include <string>

using namespace std;

class Solution {
private:
    string findPolinom(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
public:
    string longestPalindrome(string s) {
        string answer;

        for (int i = 0; i < s.length(); i++)
        {
            string odd = findPolinom(s, i, i);
            string even = findPolinom(s, i, i + 1);

            if (odd.length() > answer.length())
                answer = odd;
            if (even.length() > answer.length())
                answer = even;
        }
        return answer;
    }
};