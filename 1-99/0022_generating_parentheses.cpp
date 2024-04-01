#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParentheses(vector<string>& result, 
                        string current, 
                        int open, int close, int max,
                        int count_open, int count_close)
{
    if (count_open == max && count_close == max)
    {
        result.push_back(current);
        return;
    }

    if (open < max)
        generateParentheses(result, current + "(", open + 1, close, max, count_open + 1, count_close);
    if (close < open)
        generateParentheses(result, current + ")", open, close + 1, max, count_open, count_close + 1);
}

vector<string> generateParentheses(int n)
{
    vector<string> result;
    generateParentheses(result, "", 0, 0, n, 0, 0);
    return result;
}

int main() {
    int n = 1;
    vector<string> parentheses = generateParentheses(n);
    for (const string& p : parentheses) {
        cout << p << endl;
    }
    return 0;
}
