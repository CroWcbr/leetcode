#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> save(nums);
        sort(nums.begin(), nums.end());
        int x;
        for (int i1 = 0, i2 = nums.size() - 1; i1 < i2;)
        {
            x = nums[i1] + nums[i2];
            if (x < target)
                i1++;
            else if (x > target)
                i2--;
            else
            {
                auto it1 = find(save.begin(), save.end(), nums[i1]);
                if (nums[i1] == nums[i2])
                    i2 = find(it1 + 1, save.end(), nums[i2]) - save.begin();
                else
                    i2 = find(save.begin(), save.end(), nums[i2]) - save.begin();
                i1 = it1 - save.begin();
                if (i1 > i2)
                    return {i1, i2};
                else
                    return {i2, i1};
            }
        }
        return {};
    }
};