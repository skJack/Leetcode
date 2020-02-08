/*

Category	Difficulty	Likes	Dislikes
algorithms	Hard (36.55%)	2133	-
Tags
Companies
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/

// @lc code=start
class Solution {
public://学会面对奇偶问题，可以用两个变量保存
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int len = len1+len2;
        cout<<len<<endl;
        int a=0,b=0;//对应两个指针
        int left=-1,right=-1;
        for(int i=0;i<=len/2;i++)
        {
            left = right;
            if(a<len1&&(b>=len2||nums1[a]<nums2[b]))
            {
                //学会这种并归排序的写法
                right = nums1[a++];
            }
            else
            {
                right = nums2[b++];
            }
        }
        cout<<left<<" "<<right<<endl;
        if(int(len%2)==0)
            return (left+right)/2.0;
        else
            return right;
    }
};
