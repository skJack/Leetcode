/*

Category	Difficulty	Likes	Dislikes
algorithms	Hard (55.13%)	417	-
Tags
Companies
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
示例 1:

输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2:

输入: word1 = "intention", word2 = "execution"
输出: 5
解释: 
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/

// @lc code=start
class Solution {
public:
    //思路：硬核dp，主要是理清首先增，删，改三个操作可以抽象为dp[i-1][j],dp[i][j-1],dp[i-1][j-1](因为对a的增可以看做对b的删，所以可以转化)
    //然后我们就轻松的推到出来状态转移方程
    //dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
    //dp的定义看代码中的注释
    //这道题的难点首先是想不到用dp，其次是无法抽象出增删改三个操作
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        //dp[i][j]表示字母1的前i位到字母2的前j位的编辑距离
        vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
        //初始化dp数组,注意dp数组一定比原来多一维，因为初始化是算进去0字符，也就是计算的是0-n共n+1个数字
        for(int i=0;i<=len1;i++)
        {
            dp[i][0] = i;
        }
        for(int j=0;j<=len2;j++)
        {
            dp[0][j] = j;
        }
        for(int i=1;i<=len1;i++)
        {
            for(int j=1;j<=len2;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
        }
        return dp[len1][len2];
    }
};
