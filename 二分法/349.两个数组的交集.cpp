/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (67.70%)	164	-
Tags
Companies
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
*/
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    //方法一：用set类似哈希表的方法做（ON）
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>m;
        map<int,int>visit;
        vector<int>ans;
        int len1 = nums1.size();
        int len2 = nums2.size();
        for(int i=0;i<len1;i++)
        {
            m[nums1[i]]++;
        }
        for(int i=0;i<len2;i++)
        {
            if(m[nums2[i]]>0&&visit[nums2[i]]==0)
                ans.push_back(nums2[i]);
            visit[nums2[i]]++;
        }
        return ans;
    }
    //方法二：先排序，类似并归排序的指针做法，但是要注意筛掉重复数字
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> ans;
        int point1 = 0,point2=0;
        while (point1<len1&&point2<len2)
        {
            if(nums1[point1]>nums2[point2])
            {
                point2++;
            }
            else if(nums1[point1]<nums2[point2])
            {
                point1++;
            }
            else if(nums1[point1]==nums2[point2])
                {
                    int tmp = nums1[point1];
                    
                    ans.push_back(tmp);
                    while (nums1[point1]==tmp)
                    {
                        point1++;
                        if(point1>=len1)
                            {
                                return ans;
                            }
                    }
                    while (nums2[point2]==tmp)
                    {
                        point2++;
                        if(point2>=len2)
                            {
                                return ans;
                            }
                    }
                }    
        }
        return ans;
    }
};
// @lc code=end

