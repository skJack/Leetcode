/*
Category	Difficulty	Likes	Dislikes
algorithms	Hard (37.28%)	476	-
Tags
Companies
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

 

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
 

提示：

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
*/

// @lc code=start
class Solution {
public:
//方法：自身哈希表法。因为最后结果肯定在【1，N+1】之间，所以其实只要保证nums[i]=i,
//之后遍历这个哈希表，然后第一个不满足nums[i]==i的就是最小整数 
    void swap(vector<int>& nums,int i,int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        for(int i=0;i<len;i++)
        {
            while (nums[i]>0&&nums[i]<=len&&nums[i]!=i+1&&nums[i]&&nums[nums[i]-1]!=nums[i])
            {
                /*
        	只有在 nums[i] 是 [1, len] 之间的数，并且不在自己应该呆的位置， nums[i] != i + 1 ，
        	并且 它应该呆的位置没有被同伴占有（即存在重复值占有）	nums[nums[i] - 1] != nums[i] 的时候才进行交换
        	
        	为什么使用 while ？ 因为交换后，原本 i 位置的 nums[i] 已经交换到了别的地方，交换后到这里的新值不一定是适合这个位置的，因此需要重新进行判断交换
        	如果使用 if，那么进行一次交换后，i 就会 +1 进入下一个循环，那么交换过来的新值就没有去找到它该有的位置
        比如 nums = [3, 4, -1, 1] 当 3 进行交换后， nums 变成 [-1，4，3，1]，此时 i == 0，如果使用 if ，那么会进入下一个循环， 这个 -1 就没有进行处理
        	*/
                swap(nums,nums[i]-1,i);
            }
        }
        for(int i=0;i<len;i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return len+1;
    }
};
