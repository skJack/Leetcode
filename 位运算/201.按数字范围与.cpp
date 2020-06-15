/*
数字范围按位与
Category	Difficulty	Likes	Dislikes
algorithms	Medium (44.43%)	81	-
Tags
Companies
给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1: 

输入: [5,7]
输出: 4
示例 2:

输入: [0,1]
输出: 0
*/

// @lc code=start
class Solution {
public:
//方法一：憨批法。首先需要保证m，n是在一个2^n~2^n+1区间内才有答案
//因为除此之外的值一定会有0出现
//如果在区间内就加上高位，之后按照位置减就行
    int rangeBitwiseAnd1(int m, int n) {
        vector<int>t(32,0);
        int tmp = 1;
        for(int i=0;i<31;i++)
        {
            t[i] = pow(2,i);
        }
        int ans = 0;
        while(m>0)
        {
            int left = int(log(m)/log(2));
            int right = int(log(n)/log(2));

            if(left!=right)
            {
                //如果不相等，直接返回
                return ans;
            }
            else
            {
                //如果相等，说明在一个紧逼区间内
                ans += t[left];
                m = m-t[left];
                n = n-t[right];
            }
        }
        return ans;
    }
    //方法二：大佬法：思路一样的，但是没有再次映射到10进制空间，而是直接映射到2进制空间做。
    //只要判断n和m相等是所需要的最小位移，然后后面全部补0就是最后答案
    
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while (m!=n)
        {
            m>>=1;
            n>>=1;
            count++;    
        }
        n <<= count;
        return n;
    }
};
