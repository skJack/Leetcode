/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (33.62%)	260	-
Tags
Companies
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

*/

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)  return 0;
        double ans;
        if(x > 0 || ((x < 0) && (n % 2 == 0)))    ans = exp(n*log(abs(x)));
        else ans = -exp(n*log(-x));
        return ans;
    }
};
