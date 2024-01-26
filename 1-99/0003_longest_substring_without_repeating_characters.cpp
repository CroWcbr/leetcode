#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> myVector(128, -1);
        int str_max = 0;
        int left = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (myVector[s[i]] > left)
                left = myVector[s[i]];
            str_max = max(str_max, i - left);
            myVector[s[i]] = i;
        }
        return str_max;
    }
};