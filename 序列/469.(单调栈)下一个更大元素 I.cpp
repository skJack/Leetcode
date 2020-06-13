/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (62.54%)	215	-
Tags
Companies
给定两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。

 

示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
 
*/

// @lc code=start
class Solution {
public:
//单调栈的应用，加了一个哈希表
//单调栈问题：496 901 42 84
//遇到求单调最大问题的用这个
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if(len2<1)
            return {};
        vector<int>hash(10001,-1);
        vector<int>ans;
        stack<int>s;
        s.push(nums2[0]);
        for(int i=1;i<len2;i++)
        {
            while(!s.empty()&&nums2[i]>s.top())
            {
                int tmp = s.top();
                hash[tmp] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        for(int i=0;i<len1;i++)
        {
            ans.push_back(hash[nums1[i]]);
        }
        return ans;

        

    }
};
