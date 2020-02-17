/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (40.86%)	348	-
Tags
Companies
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:

输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。
示例 2:

输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
*/
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int add=1;//进位
        for(int i=len-1;i>=0;i--)
        {
            int tmp = digits[i]+add;
            if(tmp==10)
                add=1;
            else
                add=0;
            digits[i] = tmp%10;
        }
        if(add==1)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
