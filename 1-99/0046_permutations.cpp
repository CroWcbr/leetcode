#include <vector>

using namespace std;

class Solution {
private:
    void find(vector<int>& nums, vector<vector<int>>& answer, int start)
    {
        if (start == nums.size() - 1)
            answer.push_back(nums);
        else
        {
            for (int i = start; i < nums.size(); ++i)
            {
                swap(nums[start], nums[i]);
                find(nums, answer, start + 1);
                swap(nums[start], nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> answer;
        find(nums, answer, 0);
        return answer;
    }
};