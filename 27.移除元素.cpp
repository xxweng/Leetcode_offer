/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        int count = 0;
        int nums_length = nums.size();
        
        for(int i = 0; i < nums_length; i++)
        {
            if(nums[i] != val)
            {
                nums[index] = nums[i];
                index++;
            }
            else
            {
                nums[i] = 0;
            }
        }
        return index;
    }
};
// @lc code=end

