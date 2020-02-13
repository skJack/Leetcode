/*
最接近的三数之和
Category	Difficulty	Likes	Dislikes
algorithms	Medium (42.54%)	355	-
Tags
Companies
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/
//和15非常像，都是双指针法，一定学会这种排序+双指针解决求和问题的套路
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<len;i++)
        {
            int left = i+1;
            int right = len-1;
            while (left<right)
            {
                int tmp = nums[i]+nums[left]+nums[right];
                int m = tmp-target;
                if(abs(target-ans)>abs(target-tmp))
                {
                    ans = tmp;
                }
                if(tmp>target)
                    right--;//说明三数之和有点大了，要往小点变
                else if(tmp<target)
                    left++;//道理一样
                else
                {
                    return ans;
                }
            }
        }
        return ans;
    }
};
