/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (38.71%)	49	-
Tags
Companies
Unknown

在一个给定的数组nums中，总是存在一个最大元素 。

查找数组中的最大元素是否至少是数组中每个其他数字的两倍。

如果是，则返回最大元素的索引，否则返回-1。

示例 1:

输入: nums = [3, 6, 1, 0]
输出: 1
解释: 6是最大的整数, 对于数组中的其他整数,
6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
 

示例 2:

输入: nums = [1, 2, 3, 4]
输出: -1
解释: 4没有超过3的两倍大, 所以我们返回 -1.
 

提示:

nums 的长度范围在[1, 50].
每个 nums[i] 的整数范围在 [0, 100].
*/
// @lc code=start
class Solution {
public:
//做法一：dp，每次更新前都判断是满足情况，很蠢
    int dominantIndex1(vector<int>& nums) {
        int len = nums.size();
        if(len==1)
        {
            return 0;
        }
        int dp[len];
        bool flag = true;
        dp[0] = nums[0];
        int ans=0;
        for(int i=1;i<len;i++)
        {
            if(dp[i-1]<nums[i])
            {
                ans = i;
                dp[i] = nums[i];
                if(dp[i]>=2*dp[i-1])
                    flag = true;
                else
                    flag = false;
            }
            else 
                {
                    dp[i] = dp[i-1];
                    if(nums[i]*2>dp[i])
                        flag = false;
                }
        }
        if(flag==false)
            return -1;
        else
            return ans;
    }
    //方法二：找到最大和第二大再判断即可
    int dominantIndex(vector<int>& nums) {
        int len = nums.size();
        int max = -1;
        int max2 = -2;
        int index=0;
        for(int i=0;i<len;i++)
        {
            if(max<nums[i])
            {
                max2 = max;
                max = nums[i];
                index = i;
            }
            else if(nums[i]>max2)
                max2 = nums[i];//注意这种找第二大的写法
        }
        cout<<max<<" "<<max2;
        if(max>=max2*2)
            return index;
        else
            return -1;
    }

};
