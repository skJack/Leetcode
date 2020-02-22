/*
Category	Difficulty	Likes	Dislikes
algorithms	Medium (36.27%)	524	-
Tags
Companies
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    //思路：通过二分找到旋转点。这里注意旋转点为0，和len-1的情况需要特殊判断
    //如何找呢？我的方法是每次和最后一个数字比较作为指针移动法则，且判断条件为当前值如果比他的邻居都小则一定是旋转点
    //之后根据旋转点分别二分即可
    int bs(vector<int>& nums, int target,int left,int right)
    {
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>target)
            {
                right = mid-1;
            }
            if(nums[mid]<target)
            {
                left = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
       int len = nums.size();
       if (len==0)
       {
           return -1;
       }
       if(len==1)
       {
           if(nums[0]==target)
            return 0;
            else
            {
                return -1;
            }
       }
       //先寻找旋转点
        int left=0,right=len-1;
        int point=len;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(mid==0&&nums[mid]>nums[mid+1])
            {
                //真的是第0个数字
                point = 0;
                break;
            }
            if(mid==len-1&&nums[mid]<nums[mid-1])
            {
                //真的是最后一个数字是转折点
                point = len-1;
                break;
            }
            if((mid==0&&nums[mid]<nums[mid+1])||(mid==len-1&&nums[mid]>nums[mid-1]))
            {
                //正序数字
                point = -1;
                break;
            }
            //cout<<left<<" "<<right<<" "<<mid<<endl;
            if(nums[mid]<nums[mid+1]&&nums[mid]<nums[mid-1])
            {
                //cout<<nums[mid]<<" "<<nums[mid-1]<<" "<<nums[mid+1];
                point = mid;
                break;
            }
            if(nums[mid]>nums[len-1])
            {
                left = mid+1;
            }
            else if(nums[mid]<nums[len-1])
            {
                right = mid-1;
            }
        }
        cout<<point;
        if(point==-1)
            return bs(nums,target,0,len-1);
        if(point==0)
        {
            if(nums[0]==target)
                return 0;
            else
                return bs(nums,target,1,len-1);
        }
        if(point==len-1)
        {
            if(nums[len-1]==target)
                return len-1;
            else
            {
                return bs(nums,target,0,len-2);
            }
        }
        else
        {
            int part1 = bs(nums,target,0,point-1);
            if(part1!=-1)
                return part1;
            else
            {
                int part2 = bs(nums,target,point,len-1);
                return part2;
            }
            
        }  
        return -1;
    }
};
// @lc code=end

