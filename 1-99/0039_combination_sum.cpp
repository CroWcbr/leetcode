#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    void decision(vector<vector<int>>& answer, const vector<int>& candidates, int target, int sum, std::vector<int> tmp, int id)
    {
        sum += candidates[id];
        if (sum > target)
            return;

        tmp.push_back(candidates[id]);
        if (sum == target)
        {
            answer.push_back(tmp);
            return;
        }
        for (int i = id; i < candidates.size(); ++i)
        {
            if (sum + candidates[i] > target)
                break;
            decision(answer, candidates, target, sum, tmp, i);
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        for (int i = 0; i < candidates.size(); ++i)
            decision(answer, candidates, target, 0, std::vector<int>(), i);
        return answer;
    }
};