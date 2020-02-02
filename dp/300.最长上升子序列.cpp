/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (43.66%)	405	-
Tags
Companies
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
*/
// @lc code=start
class Solution {
public:
//思路：dp[i]存着考虑第i个数字的最大的上升子序列，则我们我们需要判断从（注意不是到第i个序列的最大，而是包含i）
//dp[i]=0~i之前所有最大的上升子序列加1
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size==0)
            return 0;
        int dp[size];
        dp[0] = 1;
        for(int i=1;i<size;i++)
        {
            int max = 0;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    if(max<dp[j])
                        max = dp[j];
                }
            }
            dp[i] = max+1;//因为都是判断的nums[i]>nums[j]，所以最后结果一定加1
        }
        int maxs = 0;
        for(int i=0;i<size;i++)
        {
            if(maxs<dp[i])
                maxs = dp[i];
        }//最后返回最大的数
        return maxs;
    }
};
