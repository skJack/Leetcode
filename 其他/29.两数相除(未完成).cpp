/*
两数相除
Category	Difficulty	Likes	Dislikes
algorithms	Medium (19.06%)	269	-
Tags
Companies
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
*/

// @lc code=start
class Solution {
public:

    int divide(int dividend, int divisor) {
        if(dividend<divisor)
            return 0;
        bool ispositive = (dividend^divisor) >=0;//用异或求出最终的符号，再都转化成负数
        int ans = 1;
        if(dividend>0)
        {
            dividend = opposite(dividend);
        }
        if(divisor>0)
        {
            divisor = opposite(divisor);
        }
        int index=0;
        int origin_dividend = dividend;
        int origin_divisor = divisor;
        dividend = dividend-divisor;//因为asn从1开始，所以先减一下
        while (dividend>=divisor)
        {
            ans += ans;//注意计数器也是加倍的加
            divisor += divisor;
            dividend = dividend-divisor;
        }
        
        int a=ans+opposite(divide(origin_dividend-divisor,origin_divisor));//大于0之前的那个数除以以前的除数
        cout<<a<<endl;
        if(ispositive)
        {
            return opposite(a);
        }
        else
        {
            return a;
        }
    }
        int opposite(int x)
    {
        //不用乘法求相反数
        return -x;//根据补码规则。只要将数字求反加一即可
    }
};
