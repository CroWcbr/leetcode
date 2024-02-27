#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n_start = 0;
        int n_end = nums.size() - 1;

        while (n_start <= n_end) {
            int tmp = n_start + (n_end - n_start) / 2;

            if (target == nums[tmp])
                return tmp;

            if (target > nums[tmp] && nums[n_end] < target && nums[n_start] > nums[tmp])
                n_end = tmp - 1;
            else if (target > nums[tmp])
                n_start = tmp + 1;
            else if (target < nums[tmp] && nums[n_start] > target && nums[n_end] < nums[tmp])
                n_start = tmp + 1;
            else if(target < nums[tmp])
                n_end = tmp - 1;
        }
        return -1;
    }
};