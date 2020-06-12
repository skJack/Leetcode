/*
三数之和
Category	Difficulty	Likes	Dislikes
algorithms	Medium (25.07%)	1779	-
Tags
Companies
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
//6月12日注：重新做了一遍，卡壳了，基本思路对的，但是没想到i要在循环，想的是双指针在外，i在里面调整了半天。问题在于潜意识没有意识到这是个on^2的问题
//三数之和一定必须得定一个去搜二三个
// @lc code=start
class Solution {
public:
//很好的题，首先先排序，因为三数之和为0一定有正有负,所以以负的基准，双指针法。当三数之和小于0时
//说明整体小，所以左指针移动，让整体变大，以此类推。
//要注意重复问题，如果下一个指针和上一个指针的值重复，则直接跳过。
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;//双指针法
        sort(nums.begin(),nums.end());//先对数组进行排序
        for(int i=0;i<len;i++)
        {
            if(nums[i]>0)
                return ans;//全是大于0不可能再有解
            if(i>0&&nums[i]==nums[i-1])
                continue;//重复的直接跳过
            int left = i+1;
            int right = len-1;
            while (left<right)
            {
                if(nums[i]+nums[left]+nums[right]==0)
                {
                    ans.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while (left<right&&nums[left]==nums[left+1])//注意这里，当等于0的时候双指针同时变，但是要注意重复，有重复要跳过
                    {
                        left++;
                    }
                    while (left<right&&nums[right]==nums[right-1])
                    {
                        right--;
                    }
                    left++;
                    right--;
                }
                else if(nums[i]+nums[left]+nums[right]<0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return ans;
    }
};
