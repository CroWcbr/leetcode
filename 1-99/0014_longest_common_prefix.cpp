#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i_str = 0;
        for (; i_str < strs[0].size(); ++i_str)
        {
            char tmp = strs[0][i_str];
            for (int i = 1; i < strs.size(); ++i)
            {
                if (strs[i][i_str] != tmp)
                    return strs[1].substr(0, i_str);
            }
        }
        return strs[0];
    }
};