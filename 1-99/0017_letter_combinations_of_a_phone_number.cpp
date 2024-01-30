#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, vector<string>> data;
        data[2] = {"a", "b", "c"};
        data[3] = {"d", "e", "f"};
        data[4] = {"g", "h", "i"};
        data[5] = {"j", "k", "l"};
        data[6] = {"m", "n", "o"};
        data[7] = {"p", "q", "r", "s"};
        data[8] = {"t", "u", "v"};
        data[9] = {"w", "x", "y", "z"};

        vector<string> answer;
        for (char d : digits)
        {
            if (answer.empty())
            {
                for(string string_data : data[d - '0'])
                    answer.push_back(string_data);
            }
            else
            {
                vector<string> tmp;
                for(string string_data : data[d - '0'])
                    for (string s : answer)
                        tmp.push_back(s + string_data);
                answer.swap(tmp);
            }
        }

        return answer;
    }
};