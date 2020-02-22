/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (51.87%)	106	-
Tags
Companies
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


示例 1:

输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
示例 2:

输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 

提示：

你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。

*/
//总结下框架：二分查找就三步走：确定你要找的值，也就是循环终止条件
//找到左指针的移动条件
//找到右指针的移动条件

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left=0,right = len-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
            {
                right = mid-1;
            }
            else 
            {
                left = mid+1;
            }
        }
        return -1;
    }
};
