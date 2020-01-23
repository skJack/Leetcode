/*
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。

示例 1:

输入: 2
输出: [0,1,1]
示例 2:

输入: 5
输出: [0,1,1,2,1,2]

*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>dp(num+1,0);
        if(num==0)
            return dp;
        dp[1] = 1;
        int bottom = 2;//以2为底
        for(int i=2;i<=num;i++)
        {
            double base_double = log(i)/log(2);
            int base = floor(base_double);
            int index = pow(2,base);//找到合理的数字
            if(abs(round(base_double) - base_double) < 0.000000000000001)//判断整数,如果为证书说明是2的次方
            {
                //cout<<"ou"<<" "<<i<<endl;
                dp[index] = 1;
            }
            else
            {
                //cout<<i<<" "<<index<<" "<<dp[index]<<" "<<dp[i-index]<<endl;
                dp[i] = dp[index]+dp[i-index];//比如dp[6] = dp[4]+dp[2],要找离i最近的2的次方
            }
        }
        return dp;
    }
};
