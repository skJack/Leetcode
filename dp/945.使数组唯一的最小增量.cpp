/*
使数组唯一的最小增量
Category	Difficulty	Likes	Dislikes
algorithms	Medium (41.56%)	39	-
Tags
Companies
给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。

返回使 A 中的每个值都是唯一的最少操作次数。

示例 1:

输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
示例 2:

输入：[3,2,1,2,1,7]
输出：6
解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
提示：

0 <= A.length <= 40000
0 <= A[i] < 40000
*/

// @lc code=start
class Solution {
public:
    //思路：先排序，之后观察发现只要第i个数字变成前一个数字+1就是最小解，根据这个观察可以得到
    //dp[i] = dp[i-1]+A[i-1]-A[i]+1;
    //注意每次要更新数组A
    int minIncrementForUnique(vector<int>& A) {
        int len = A.size();
        if(len==1||len==0)
            return 0;
        sort(A.begin(),A.end());
        vector<int>dp(len,0);
        for(int i=1;i<len;i++)
        {
            if(A[i]>A[i-1])
                dp[i] = dp[i-1];
            else
                {
                    dp[i] = dp[i-1]+A[i-1]-A[i]+1;
                    A[i] = A[i-1]+1;
                }
        }
        return dp[len-1];

    }
};
