#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> mergedNum;
    std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(mergedNum));

    double answer;
    int len = mergedNum.size();
    if (len % 2)
        answer = mergedNum[len / 2];
    else
        answer = (mergedNum[len / 2 - 1] + mergedNum[len / 2]) / 2.0;
    return answer;
    }
};