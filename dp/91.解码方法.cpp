/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (22.20%)	226	-
Tags
Companies
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

*/
//自己的方法，很接近题解，但是0的问题没有处理好
//发现当当前字符和前一个字符在10~26之内，则dp[i] = dp[i-1]+dp[i-2]
//否则dp[i] = dp[i-1]
//若s[i]=0,s[i-1]为1或者2，则dp[i]=dp[i-2]否则直接返回0
class Solution {
public:
    int numDecodings1(string s) {
        int size = s.size();
        int dp[size];
        if(size==0)
            return 0;
        if(size==1&&s[0]!='0')
            return 1;
        if(s[0]=='0')
            return 0;
        dp[0] = 1;
        if(s[1]=='0')
        {
            if(s[0]=='1'||s[0]=='2')
                dp[1] = 1;
            else
                return 0;
        }
        else if((s[0]=='1'&&('1'<=s[1]<='9'))||(s[0]=='2'&&('1'<=s[1]&&s[1]<='6')))
            {
                dp[1] = 2;
            }
        else
            {
                dp[1] = 1;
            }
        for(int i=2;i<size;i++)
        {
            if(s[i]=='0')
            {
                if(s[i-1]=='1'||s[i-1]=='2')
                    dp[i] = dp[i-2];
                else
                    return 0;
            }
            else if((s[i-1]=='1'&&'1'<=s[i]<='9')||s[i-1]=='2'&&'1'<=s[i]&&s[i]<='6')
                dp[i] = dp[i-1]+dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        for(int i=0;i<size;i++)
        {
            cout<<dp[i]<<" "<<endl;
        }
        return dp[size-1];
    }////方法二：思路一样，但是通过简化状态空间，将dp数组变成变量，大大简化了代码，而且避免出现dp[i-2]
    int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2') curr = pre;
            else return 0;
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;
        pre = tmp;
    }
    return curr;
}
};
