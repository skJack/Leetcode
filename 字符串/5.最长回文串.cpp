/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (27.59%)	1446	-
Tags
string | dynamic-programming

Companies
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/
//中心扩展算法
class Solution {
public://从中心判断是否是回文串并返回最大长度
    int expand_form_center(string &s,int left,int right)
    {
        int len = s.size();
        int l = left;
        int r = right;
        while (l>=0&&r<len && s[l]==s[r])
        {
            l--;
            r++;
        }
        return r-l-1;//注意边界条件 多加了一个
    }
    string longestPalindrome(string s) {

        int len = s.size();
        int ans = 0;
        int max_center = 0;
        int start=0;
        int end=0;
        for(int i =0;i<len;i++)
        {
            int len1 = expand_form_center(s,i,i);//判断奇数串
            int len2 = expand_form_center(s,i,i+1);//判断偶数串
            int max_len = max(len1,len2);
            //cout<<i<<":"<<len1<<" "<<len2<<endl;
            if(end-start<max_len)
                {
                    start = i-(max_len-1)/2;
                    end = i+max_len/2;
                }
        }
        //cout<<max_center<<" "<<ans;
        return s.substr(start,end-start+1);
    }
};
