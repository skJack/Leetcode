/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (44.24%)	50	-
Tags
Companies
给定一个只包含小写字母的有序数组letters 和一个目标字母 target，寻找有序数组里面比目标字母大的最小字母。

数组里字母的顺序是循环的。举个例子，如果目标字母target = 'z' 并且有序数组为 letters = ['a', 'b']，则答案返回 'a'。

示例:

输入:
letters = ["c", "f", "j"]
target = "a"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "c"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "d"
输出: "f"

输入:
letters = ["c", "f", "j"]
target = "g"
输出: "j"

输入:
letters = ["c", "f", "j"]
target = "j"
输出: "c"

输入:
letters = ["c", "f", "j"]
target = "k"
输出: "c"
注:

letters长度范围在[2, 10000]区间内。
letters 仅由小写字母组成，最少包含两个不同的字母。
目标字母target 是一个小写字母。
*/


// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int len = letters.size();
        int left = 0,right = len-1;
        if(target >= letters[right] || target < letters[left])  return letters[left]; 
        while (left+1<right)
        {
            int mid = left+(right-left)/2;
            cout<<mid<<" ";
            if(letters[mid]>target)
                right = mid;
            else
            {
                left = mid;
            }
        }
        return letters[right];
    }
    
    char nextGreatestLetter1(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        if(target >= letters[r] || target < letters[l])  return letters[l]; //因为是循环数组，如果target不在数组范围内，直接返回数组第一个字符
        while(l + 1 < r){ // 二分法模板③，l始终在目标字符或者目标字符的左边，r 始终再目标字符的右边，当两者相遇跳出循环时，r刚好在目标字符位置的右边
            int mid = l + (r - l)/2;
            if(letters[mid] > target) r = mid;
            else    l = mid;
        }
        return letters[r];
    }
};
