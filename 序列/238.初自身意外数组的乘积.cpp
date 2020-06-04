/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (65.40%)	460	-
Tags
Companies
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

 

示例:

输入: [1,2,3,4]
输出: [24,12,8,6]
 

提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。

进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/

// @lc code=start
class Solution {
public:
    //方法一：ans[i] = i左边的乘积*i右边的乘积
    //所以只要记录i左侧的所有数字的乘积和i右侧的乘积，再乘起来即可
    vector<int> productExceptSelf1(vector<int>& nums) {
        int len = nums.size();
        vector<int>left(len);//left[i]表示i左侧的所有数数字的乘积
        vector<int>right(len);
        vector<int>ans(len);
        left[0] = 1;
        for(int i = 1;i<len;i++)
        {
            left[i] = left[i-1]*nums[i-1];
        }
        right[len-1] = 1;
        for(int i=len-2;i>=0;i--)
        {
            right[i] = right[i+1]*nums[i+1];
        }
        for(int i=0;i<len;i++)
        {
            ans[i] = right[i]*left[i];
        }
        return ans;
    }
    //方法二：将left数组看做最后的数组，动态的计算right数组，其实就是直接最后两个步骤合并
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int>left(len);
        left[0] = 1;
        for(int i = 1;i<len;i++)
        {
            left[i] = left[i-1]*nums[i-1];
        }
        int r = 1;//用单变量r代替right数组
        for(int i=len-1;i>=0;i--)
        {
            left[i] = left[i]*r;
            r = r*nums[i];
        }
        return left;
    }

};
