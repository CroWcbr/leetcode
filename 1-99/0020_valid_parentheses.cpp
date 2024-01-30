#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tmp;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                tmp.push(c);
            else if (tmp.empty())
                return false;
            else
            {
                if (c == ')' && tmp.top() == '(')
                    tmp.pop();
                else if (c == '}' && tmp.top() == '{')
                    tmp.pop();
                else if (c == ']' && tmp.top() == '[')
                    tmp.pop();
                else
                    return false;
            }
        }
        if (!tmp.empty())
            return false;
        return true;
    }
};