#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it, it_end;
        for (it = nums.begin(), it_end = nums.end(); it != it_end;)
        {
            if (*it == val)
                *it = *(--it_end);
            else
                ++it;
        }
        nums.erase(it_end, nums.end());
        return nums.size();
    }
};