/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (37.36%)	305	-
Tags
Companies
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。

*/

// @lc code=start
class Solution {
public:
    int mySqrt1(int x) {
        long pre;
        for(long i=0;i<=x;i++)
        {
            if(i*i>x)
                return pre;
            if(i*i==x)
                return i;
            pre = i;
        }
        return pre;
    }
    //二分法
    int mySqrt(int x) {
        long ans;
        if(x<2)
            return x;
        else
        {
            int left = 2;
            int right = x/2;
            int pre=right;
            while (left<=right)
            {
                long num = (left+right)/2;
                if(num*num>x)
                {
                    right = num-1;
                }
                if(num*num<x)
                {
                    left = num+1;//注意必须+1不然会死循环。因为/2会有月数
                }
                if(num*num==x)
                    return num;
            }
            return right;
        }
    }
};
