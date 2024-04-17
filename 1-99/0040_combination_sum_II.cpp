#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void find(vector<int>& candidates,
                int target, 
                vector<vector<int>>& answer,
                vector<int>& tmp,
                int sum,
                int start)
    {
        if (sum > target)
            return;
        else if (sum == target)
            answer.push_back(tmp);

        for (int i = start; i < candidates.size(); ++i)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            find(candidates, target, answer, tmp, sum, i + 1);
            sum -= tmp.back();
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> answer;
        vector<int> tmp;
        find(candidates, target, answer, tmp, 0, 0);

        return answer;
    }
};