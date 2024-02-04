#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> check_v(10, false);
        vector<bool> check_h(10, false);
        vector<bool> check_s(10, false);
        int tmp;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                tmp = board[i][j] - '0';
                if (tmp >= 0)
                {
                    if (check_h[tmp])
                        return false;
                    check_h[tmp] = true;
                }

                tmp = board[j][i] - '0';
                if (tmp >= 0)
                {
                    if (check_v[tmp])
                        return false;
                    check_v[tmp] = true;
                }

                tmp = board[(i / 3) * 3 + j / 3][(i % 3) * 3 + j % 3] - '0';
                if (tmp >= 0)
                {
                    if (check_s[tmp])
                        return false;
                    check_s[tmp] = true;
                }
            }

            for (int j = 0; j < 10; ++j)
                check_v[j] = check_h[j] = check_s[j] = false; 
        }
        return true;
    }
};