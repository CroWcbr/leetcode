#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            if (i > 0 && i < n - 1 && nums[i] == nums[i - 1])
                continue;
            int tmp = -nums[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] == tmp)
                {
                    answer.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    while (j + 1 < k && nums[j] == nums[j + 1])
                        j++;
                    while (j < k - 1 && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > tmp)
                    k--;
                else
                    j++;
            }
        }
        return answer;
    }
};