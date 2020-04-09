/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (72.50%)	621	-
Tags
Companies
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

// @lc code=start
class Solution {
public:
    //思路：dfs和回溯，只要open>1，说明允许添加右括号
    vector<string> generateParenthesis1(int n) {
        vector<string> ans;
        generator(ans,"",0,0,n);
        return ans;
    }
    void generator(vector<string> &ans,string cur,int open,int close,int max)
    {
        //递归的方式生成串.
        if(cur.size() == max*2)//递归终止条件,当当前子树为max的两倍
        {
            ans.push_back(cur);
            return;
        }
        if(open<max)//open代表左括号的数量，close代表右括号的数量
        //当open<比max小的时候，可以添加左括号
            generator(ans,cur+'(',open+1,close,max);
        if(open>close)//只有当左括号数量大于右括号数量的时候，才能添加右括号
            generator(ans,cur+')',open,close+1,max);
    }
    //方法二：dp.思路：所有的dp[i] = "("+p+")"+q
    //其中p和q是dp[i-1]的所有组合
    //将所有组合抽象成括号内和括号外。合理利用了之前计算的中间结果，很赞
    vector<string> generateParenthesis(int n) {
        if(n==0)
            return {};
        if(n==1)
            return {"()"};
        vector<vector<string>> dp(n+1);
        dp[0] = {""};
        dp[1] = {"()"};
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                for(string p:dp[j])
                {
                    for(string q:dp[i-j-1])
                    {
                        string tmp = "("+p+")"+q;
                        dp[i].push_back(tmp);
                    }
                }
            }
        }
        return dp[n];
    }
};
