#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // for (auto it = nums.begin(); it + 1 != nums.end();)
        // {
        //     if (*it == *(it + 1))
        //         it = nums.erase(it);
        //     else
        //         ++it;
        // }
        auto it = std::unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        return nums.size();
    }
};