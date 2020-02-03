/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (52.60%)	291	-
Tags
Companies
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.
*/
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        //vector<int> dp(n + 1);
        int dp[n+1];
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            dp[i] = i;
            for(int j=1;i>=j*j;j++)
            {
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
    struct Node
    {
        int val;
        int step;
        Node (int v,int s)
        {
            val=v;
            step = s;
        }
    };
    //方法二：BFS遍历树，注意因为要求树高，所以要设置一个结构体来保存每个节点的高度
    int numSquares(int n)
    {
        queue<Node> q;
        set<int>visit;
        visit.insert(n);
        Node node(n,0);
        q.push(node);
        while(!q.empty())
        {
            Node root = q.front();
            q.pop();
            int current_step = root.step;
            if(root.val==0)
                return current_step;
            int j;
            for(j=1;root.val>=j*j;j++)
            {
                int base = root.val-j*j;
                if(visit.find(base)==visit.end())
                {
                    //没找到
                    visit.insert(base);
                    Node tmp(base,current_step+1);
                    q.push(tmp);
                }
                //cout<<root-j*j<<endl;
            }
        }
        return -1;
        
    }
};
