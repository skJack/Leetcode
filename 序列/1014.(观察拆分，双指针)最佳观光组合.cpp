/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (46.63%)	140	-
Tags
Companies
给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。

一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。

返回一对观光景点能取得的最高分。

 

示例：

输入：[8,1,5,2,6]
输出：11
解释：i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
 

提示：

2 <= A.length <= 50000
1 <= A[i] <= 1000
*/

// @lc code=start
class Solution {
public:
//自己的方法：维护前面最大和后面最大的方法
    int maxScoreSightseeingPair1(vector<int>& A) {
        int len = A.size();
        vector<int>dp(len,0);
        int first=A[0],first_index=0,second = A[0],second_index=0;
        dp[0] = A[0];
        for(int i=1;i<len;i++)
        {
            int tmp = max(first+A[i]+first_index-i,second+A[i]+second_index-i);
            if(dp[i-1]>tmp)
            {
                dp[i] = dp[i-1];
            }
            else
            {
                dp[i] = tmp;
                if(first+A[i]+first_index-i>second+A[i]+second_index-i)
                {
                    
                    second = A[i];
                    second_index = i;
                }
                else
                {
                    first = second;
                    first_index = second_index;
                    second = A[i];
                    second_index = i;
                }
            }
        }
        for(int i=0;i<len;i++)
        {
            cout<<dp[i]<<" ";
        }
        return dp[len-1];
    }
    //观察式子，可以发现可以看成A[i]+i最大和A[j]-j最大，正好遍历j的时候可以维护前面的最大值
   //这种题要先优化一下表达式，看能不能保存之前的答案
    int maxScoreSightseeingPair(vector<int>& A) {
        int len = A.size();
        int mx = A[0];
        int ans=0;
        for(int j=1;j<len;j++)
        {
            ans = max(ans,mx+A[j]-j);
            mx = max(mx,A[j]+j);
        }
        return ans;
    }
};
