
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto it = lower_bound(nums.begin(), nums.end(), 1);

        int tmp = 1;
        while (it != nums.end() && *it == tmp)
        {
            while (it != nums.end() && *it == tmp)
                ++it;
            tmp++;
        }
        return tmp;
    }
};