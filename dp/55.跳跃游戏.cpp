/*
跳跃游戏
Category	Difficulty	Likes	Dislikes
algorithms	Medium (37.58%)	451	-
Tags
Companies
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
*/

// @lc code=start
class Solution {
public:
    //方法一：dp
    bool canJump1(vector<int>& nums) {
        int len = nums.size();
        vector<int>dp(len,0);
        if(len==0)
            return false;
        dp[0] = 1;
        for(int i=1;i<len;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j]==1&&nums[j]>=i-j)
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        for(int i=0;i<len;i++)
        {
            cout<<dp[i]<<" ";
        }
        return dp[len-1];
    }
    //方法二：逆序最后能跳到1就行
    bool canJump2(vector<int>& nums) {
        int last = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--) 
            if(last - i <= nums[i]) last = i;
        return last == 0;
    }
    //方法三：记录最远
    bool canJump(vector<int>& nums) 
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
