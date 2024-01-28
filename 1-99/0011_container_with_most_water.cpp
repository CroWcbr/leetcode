#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        auto left = height.begin();
        auto right = height.end() - 1;

        int answer = 0;

        while (left != right)
        {
            // int tmp = distance(left, right) * min(*left, *right);
            answer = max(answer, static_cast<int>(std::distance(left, right)) * min(*left, *right));
            
            if (*left > *right)
                right--;
            else
                left++;
        }

        return answer;
    }
};

int main()
{
    Solution test;

    vector<int> tmp = {1,8,6,2,5,4,8,3,7};
    cout << test.maxArea(tmp) << endl;
}
