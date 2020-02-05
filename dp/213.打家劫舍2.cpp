/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (35.81%)	172	-
Tags
Companies
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
*/
//解释：就是抛去第一个房间dp1和抛去最后一个房间dp2，最后求max(dp1[last],dp2[last])
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len==0)
            return 0;
        if(len==1)
            return nums[0];
        if(len==2)
            return max(nums[0],nums[1]);
        int dp1[len-1];
        int dp2[len-1];
        dp1[0] = nums[0];//抛去最后一个
        dp1[1] = max(nums[1],nums[0]);
        for(int i=2;i<len-1;i++)
        {
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]);
        }
        dp2[0] = nums[1];
        dp2[1] = max(nums[2],nums[1]);
        for(int j=2;j<len-1;j++)
        {
            dp2[j] = max(dp2[j-1],dp2[j-2]+nums[j+1]);
        }
        return max(dp1[len-2],dp2[len-2]);
    }
};
