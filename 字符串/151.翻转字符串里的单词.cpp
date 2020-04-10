/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (32.93%)	91	-
Tags
Companies
给定一个字符串，逐个翻转字符串中的每个单词。

 

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 

说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
*/

// @lc code=start
class Solution {
public:
    //思路：先做一个数组存word，然后再连接起来
    string reverseWords(string s) {
        string ans = "";
        int len = s.size();
        vector<string>word;
        int i=0;
        while (i<len)
        {
            string tmp = "";
            while (s[i]==' '&&i<len)
            {
                i++;
            }
            while(s[i]!=' '&&i<len)
            {
                tmp.push_back(s[i]);
                i++;
            }
            if(tmp.size()>0)
                word.push_back(tmp);
            // cout<<i<<" ";
            cout<<tmp.size()<<" "<<tmp<<endl;
        }

        reverse(word.begin(),word.end());
        for(int j = 0;j<word.size();j++)
        {
            cout<<word[j]<<" ";
            if(j==word.size()-1)
                ans += word[j];
            else
                ans += word[j]+' ';
        }
        return ans;
    }
};
