/*
整数拆分
Category	Difficulty	Likes	Dislikes
algorithms	Medium (53.70%)	145	-
Tags
Companies
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
*/
class Solution {
public:
    //思路：dp[i]是可以由以前的产生，只要判断是以前最大即可
    int integerBreak(int n) {
        vector<int>dp(n+1,0);
        dp[1] = 0;
        dp[2] = 1;
        if(n==2)
            return dp[2];
        dp[3] = 2;
        for(int i=4;i<=n;i++)
        {
            for(int j=1;j<=i/2;j++)
            {
                int m = i-j;
                int tmp1 = max(dp[j],j);
                int tmp2 = max(dp[m],m);
                dp[i] = max(dp[i],tmp1*tmp2);
            }
        }
        for(int i=0;i<=n;i++)
        {
            cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[n];
    }
};
