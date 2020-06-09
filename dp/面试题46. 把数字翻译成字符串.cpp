/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 

提示：

0 <= num < 231
通过次数23,475提交次数43,599
*/
class Solution {
public:
    //方法一 数组dp，比较容易想但是很慢
    int translateNum1(int num) {
        int temp = num;
        if(num<10)
            return 1;
        vector<int>d;
        while(num>0)
        {
            int digit = num%10;
            d.push_back(digit);
            num = num/10;
        }
        reverse(d.begin(),d.end());
        int len = d.size();
        vector<int>dp(len+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=len;i++)
        {
            if(d[i-2]!=0 && (d[i-2]*10+d[i-1])<=25)
                dp[i] = dp[i-1]+dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        return dp[len];
    }
    //方法二：首先用变量代替dp数组。其次注意正向反向一样的，可以处理成一个循环来做。
    int translateNum(int num) {
        int ans = 0,i=1,j=1,digit;
        int y = num%10;
        while(num!=0)
        {
            num/=10;
            digit = num%10;
            int temp = 10 * digit + y;
            int k = (temp>=10 && temp<=25)? i+j: i;
            j = i;
            i = k;
            y = digit;
        }
        return i;
    }
};
