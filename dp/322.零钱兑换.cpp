/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (36.96%)	344	-
Tags
Companies
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:

输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1
示例 2:

输入: coins = [2], amount = 3
输出: -1
说明:
你可以认为每种硬币的数量是无限的。

*/
//该题和279思路有点像，都是遍历n之前的数，然后好找。也可以用dfs遍历树做。
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        sort(coins.begin(),coins.end());
        
        if(len==0||amount==0)
            return 0;
        if(amount<coins[0])
            return -1;
        vector<int> dp(amount+1,amount+1);
        for(int i=0;i<len;i++)
        {
            if(amount>=coins[i])
                dp[coins[i]] = 1;
        }
        for(int i=coins[0]+1;i<=amount;i++)
        {
            int j;
            for(j=0;j<len;j++)
            {
                if(i-coins[j]>=0)
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);//dp推导式
            }
        }
        for(int i=0;i<=amount;i++)
        {
            cout<<dp[i]<<endl;
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};
