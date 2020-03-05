/*
Category	Difficulty	Likes	Dislikes
algorithms	Medium (43.95%)	157	-
Tags
Companies
峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞。

示例 1:

输入: nums = [1,2,3,1]
输出: 2
解释: 3 是峰值元素，你的函数应该返回其索引 2。
示例 2:

输入: nums = [1,2,1,3,5,6,4]
输出: 1 或 5 
解释: 你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
说明:

你的解法应该是 O(logN) 时间复杂度的。
*/

// @lc code=start
class Solution {
public:
    //方法一：暴力。主要是要了解只需判断nums[i]和nums[i+1]的值
    int findPeakElement1(vector<int>& nums) {
        int len = nums.size();
        //nums.push_back(__INT_MAX__)
        for(int i=0;i<len-1;i++)
        {
            if(nums[i]>nums[i+1])
                return i;
        }
        return len-1;
    }
    //方法二：二分法，判断mid的值处于上升序列还是下降序列。
    //如果nums[mid]>nums[mid+1],则处于上升序列，说明峰值在他的右边，
    //如果nums[mid]<nums[mid-1],则处于下降序列,则峰值一定在其左边
    //
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len-1;
        while (left<right)
        {
            int mid = (left+right)/2;
            if(nums[mid]<nums[mid+1])
            {
                //上升序列
                left = mid+1;
            }
            else
            {
                //下降序列
                right = mid;
            }
        } 
        return right;
    }
};
