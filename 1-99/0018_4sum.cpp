#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for (int a = 0, n = nums.size(); a < n; ++a)
        {
            if (a > 0 && a < n - 1 && nums[a] == nums[a - 1])
                continue;

            for (int b = a + 1; b < n; ++b)
            {
                if (b > a + 1 && b < n - 1 && nums[b] == nums[b - 1])
                    continue;
                int j = b + 1;
                int k = n - 1;
                while (j < k)
                {
                    long  long int tmp = static_cast<long  long int>(nums[a]) + nums[b] + nums[j] + nums[k];
                    if (tmp == target)
                    {
                        answer.push_back(vector<int>{nums[a], nums[b], nums[j], nums[k]});
                        while (j + 1 < k && nums[j] == nums[j + 1])
                            j++;
                        while (j < k - 1 && nums[k] == nums[k - 1])
                            k--;
                        j++;
                        k--;
                    }
                    else if (tmp > target)
                        k--;
                    else
                        j++;
                }
            }
        }
        return answer;
    }
};