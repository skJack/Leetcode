/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (53.63%)	218	-
Tags
Companies
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:

输入: [3,0,1]
输出: 2
示例 2:

输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?

Discussion | Solution
*/
// @lc code=start
//等差数列求和，做减法即可
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum=0;
        int m = -1;
        int expect_sum = ((0+len)*(len+1))/2;
        for(int i=0;i<len;i++)
        {
            sum+=nums[i];
        }
        return expect_sum-sum;
    }
};
