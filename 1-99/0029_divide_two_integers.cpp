#include <cmath>
#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long dividend_long = labs(dividend);
        long long divisor_long = labs(divisor);
        
        long long result = 0;
        while (dividend_long >= divisor_long)
        {
            long long temp_divisor = divisor_long;
            long long current_power = 1;
            while ((temp_divisor << 1) <= dividend_long)
            {
                temp_divisor <<= 1;
                current_power <<= 1;
            }
            dividend_long -= temp_divisor;
            result += current_power;
        }
        
        if (sign == -1) result = -result;
        
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        
        return result;
    }
};