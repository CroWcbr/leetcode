#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> data(nums.size(), 0);
        int point = 1;
        data[0] = 1;
        for (int i = 0; point < nums.size(); ++i)
            for (; point < nums.size() && point <= i + nums[i]; ++point)
                if (data[i])
                    data[point] = data[i] + 1; 
        return (data.back() ? true : false);
    }
};

int main()
{
    Solution tmp;

    vector<int> data = {1,2,1,1,1};

    cout << tmp.canJump(data) << endl;
    return 0;
}