#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int compare = abs(nums[0] + nums[1] + nums[2] - target);
        int answer = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            if (i > 0 && i < n - 1 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int tmp = abs(nums[i] + nums[j] + nums[k] - target);
                if (tmp < compare)
                {
                    compare = tmp;
                    answer = nums[i] + nums[j] + nums[k];
                }
                if (answer == target)
                    return target;
                else if (nums[i] + nums[j] + nums[k] > target)
                    k--;
                else
                    j++;
            }
        }
        return answer;
    }
};