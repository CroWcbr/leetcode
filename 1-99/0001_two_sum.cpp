#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> save;

        for (int i = 0; i < nums.size(); ++i)
        {
            if ((target >= 0 && nums[i] >= INT_MIN + target) || 
                (target < 0 && nums[i] <= INT_MAX + target))
            {
                auto it = save.find(target - nums[i]);
                if (it != save.end())
                    return {it->second, i};
            }
            save[nums[i]] = i;
        }

        return {};
    }
};