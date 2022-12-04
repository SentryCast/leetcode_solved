// https://leetcode.com/problems/median-of-two-sorted-arrays/

// Given two sorted arrays nums1 and nums2 of size m and n respectively,
// return the median of the two sorted arrays.

// The overall run time complexity should be O(log(m + n)).

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // merge
        vector<int> mergedNums;

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                mergedNums.push_back(nums1[i++]);
            }
            else
            {
                mergedNums.push_back(nums2[j++]);
            }
        }

        while (i < nums1.size())
        {
            mergedNums.push_back(nums1[i++]);
        }

        while (j < nums2.size())
        {
            mergedNums.push_back(nums2[j++]);
        }

        if (mergedNums.size() == 0)
        {
            return 0.0;
        }
        if (mergedNums.size() == 1)
        {
            return mergedNums[0];
        }

        if (mergedNums.size() % 2 == 0)
        {
            return (mergedNums[mergedNums.size() / 2 - 1] + mergedNums[mergedNums.size() / 2]) / 2.0;
        }
        else
        {
            return mergedNums[mergedNums.size() / 2];
        }
    }
};

int main()
{

    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    // answer should be 2.5
    Solution s;
    cout << "res: " << s.findMedianSortedArrays(nums1, nums2) << endl;

    cout << 1 % 2 << endl;
    cout << 1 / 2 << endl;
    return 0;
}