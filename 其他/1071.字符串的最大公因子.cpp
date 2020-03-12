/*
Category	Difficulty	Likes	Dislikes
algorithms	Easy (48.98%)	104	-
Tags
Companies
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。

返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

 

示例 1：

输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"
示例 2：

输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"
示例 3：

输入：str1 = "LEET", str2 = "CODE"
输出：""
 

提示：

1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] 和 str2[i] 为大写英文字母
*/


// @lc code=start
class Solution {
public:
    //最大公约数方法：gcd
    int gcd1(int a,int b)
    {
        if(b==0)
            return a;
        else
        {
            gcd(b,a%b);
        }
    }
    //思路就是找到两个数长度的最大公约数，这个最大公约数一定是子串的最大长度。
    //这一点我想到了，但我还以为需要求最小的子串大意了，我智商还是可以的。
    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        cout<<gcd(len1,len2);
        if(str1+str2 == str2+str1)
        {
            return str1.substr(0,gcd(len1,len2));
        }
        else
        {
            return "";
        }   
    }
};
