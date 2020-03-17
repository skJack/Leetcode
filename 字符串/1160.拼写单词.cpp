/*
拼写单词
Category	Difficulty	Likes	Dislikes
algorithms	Easy (64.11%)	53	-
Tags
Companies
给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。

 

示例 1：

输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释： 
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
示例 2：

输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
输出：10
解释：
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
 

提示：

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
所有字符串中都仅包含小写英文字母
*/

// @lc code=start
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>hash;
        int len = chars.size();
        int ans=0;
        for(int i=0;i<len;i++)
        {
            hash[chars[i]]++;
        }
        int word_len = words.size();
        for(int i=0;i<word_len;i++)
        {
            map<char,int>tmp = hash;
            bool flag = true;
            for(int j=0;j<words[i].size();j++)
            {
                char current = words[i][j];
                tmp[current]--;
                if(tmp[current]<0)
                {
                    flag = false;
                    break;
                }                
            }
            if(flag==true)
            {
                ans+=words[i].size();
            }
        }
        return ans;
    }
};
