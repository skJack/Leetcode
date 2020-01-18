/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。


*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int dp[size] = {0};//dp[i]表示已nums[i]结尾的当前最大子数组和，我们要求的是dp[0]~dp[size]最大的大小
        dp[0] = nums[0];
        int result = dp[0];//最大子数组的和
        for(int i=1;i<size;i++)
        {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);//要不就是前一天加上今天，要不就是紧要今天
            result = max(dp[i],result);//注意要计算全局最优
        }
        return result;
    }
};
