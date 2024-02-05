#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string answer("1");
        for (int i = 2; i <= n; ++i)
        {
            std::string tmp_s;
            for (int j = 0; j < answer.size();)
            {
                char tmp = answer[j];
                int count = 0;
                while (answer[j] == tmp)
                {
                    count++;
                    j++;
                }
                tmp_s += to_string(count);
                tmp_s += tmp;
            }
            swap(tmp_s, answer);
        }
        return answer;
    }
};