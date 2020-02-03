/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (48.81%)	201	-
Tags
Companies
编写一个程序，找出第 n 个丑数。

丑数就是只包含质因数 2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。
*/
//这个问题要想到一点是每一个新的数都是由前面的数分别乘以3，2，5得到的，最后再排个序就可以。
//可以使用优先队列，但是dp更加优雅，只要往前调整指针即可。
class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int index_2=0;
        int index_3=0;
        int index_5=0;
        for(int i=1;i<n;i++)
        {
            dp[i] = min(min(2*dp[index_2],3*dp[index_3]),5*dp[index_5]);//注意c++min三个数的写法
            if(dp[i]==2*dp[index_2])
            {
                index_2++;
            }
            if(dp[i]==3*dp[index_3])
            {
                index_3++;
            }
            if(dp[i]==5*dp[index_5])
            {
                index_5++;
            }
        }
        return dp[n-1];
    }
};
