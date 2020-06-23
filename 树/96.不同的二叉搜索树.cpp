/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (64.20%)	367	-
Tags
Companies
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
Discussion | Solution
*/

// @lc code=start
class Solution {
public:
//自己做出来的 感觉有点厉害
//这个题需要推导一下过程，首先想到中序遍历是一定的，然后递归的把
//每个点做根的情况递归的考虑就可以退出递归表达式
    int numTrees(int n) {
        if(n<=1)
            return n;
        vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3;i<=n;i++)
        {
            int ans = 0;
            for(int j=0;j<i;j++)
            {
                ans+=dp[i-j-1]*dp[j];
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};
