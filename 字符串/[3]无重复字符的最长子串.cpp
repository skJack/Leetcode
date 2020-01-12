
Category	Difficulty	Likes	Dislikes
algorithms	Medium (31.94%)	2675	-
Tags
Companies
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int len = s.size();
        int hashmap[256] = {0};
        int flag = 0;
        int current = 0;
        int result = current;
        int i=0;
        for(i=0;i<len;i++)
        {
            if(hashmap[s[i]] != 0)
            {
                //这个子串有重复
                current = i-flag;
                if (result < current)
                    result = current;
                //清除哈希表
                for(;flag<i;flag++)
                {
                    if(s[flag]!=s[i])
                        hashmap[s[flag]] = 0;
                    else
                        break;
                }
                hashmap[s[i]] = 1;
                flag++;
            }
            else{
                hashmap[s[i]] = 1;//置0
            }
        }
        //处理没有重复的情况。
        current = i-flag;
        if (result < current)
            result = current;

        return result;
    }
};
/*
//方法二：滑动窗口 就是我的方法的进阶
int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int left = -1;
        int ans = 0;
        for(int i=0;i<s.size();++i){
            if(hash[s[i]] > left){
                left = hash[s[i]];
            }
            ans = max(ans,i-left);
            hash[s[i]] = i;
        }
        return ans;
    }
