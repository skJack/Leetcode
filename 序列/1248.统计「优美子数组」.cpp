/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (46.67%)	55	-
Tags
Companies
给你一个整数数组 nums 和一个整数 k。

如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

请返回这个数组中「优美子数组」的数目。

 

示例 1：

输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
示例 2：

输入：nums = [2,4,6], k = 1
输出：0
解释：数列中不包含任何奇数，所以不存在优美子数组。
示例 3：

输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出：16
 

提示：

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length

*/

// @lc code=start
class Solution {
public:
    //思路：滑动窗口。首先意识到当right走到num_odd=k的时候，left指针前面所有
    //的偶数l和right后面所有的偶数r加一的乘积就是这一小段窗口的所有组合 ans+=(l+1)(r+1)
    //之后再进行循环
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left=0,right=0;
        int len = nums.size();
        int ans=0;
        int num_odd=0;
        while (right<len)
        {
            if(nums[right++]%2!=0)
            {
                //奇数
                num_odd++;
            }
            if(num_odd==k)
            {
                // 先将滑动窗口的右边界向右拓展，直到遇到下一个奇数（或出界）
                // r 即为第 k 个奇数右边的偶数的个数

                int tmp = right;
                while (right<len&&nums[right]%2==0)
                {
                    right++;
                }
                int r = right-tmp;
                int l = 0;
                while (nums[left]%2==0)
                {
                    left++;
                    l++;
                }
                ans+=(r+1)*(l+1);
                 // 此时 left 指向的是第 1 个奇数，因为该区间已经统计完了，因此 left 右移一位，oddCnt--
                left++;
                num_odd--;
            }
            
        }
        return ans;
    }
};
