#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
        vector<int> data(nums.size(), 0);
        int point = 1;
        for (int i = 0; point < nums.size(); ++i)
            for (; point < nums.size() && point <= i + nums[i]; ++point)
                data[point] = data[i] + 1; 
        return data.back();
    }
};

int main()
{
    Solution tmp;

    vector<int> data = {1,2,1,1,1};

    cout << tmp.jump(data) << endl;
    return 0;
}