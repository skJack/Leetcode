/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (54.29%)	435	-
Tags
Companies
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:
不能使用代码库中的排序函数来解决这道题。

示例:

输入: [2,0,2,1,1,0]
输出: [0,0,1,1,2,2]
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？
*/

// @lc code=start
class Solution {
public:
    void swap(vector<int>& nums,int i,int j)
    {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    //思路：双指针法
    //左右两个指针分别指向0和2的边界
    //最后一个遍历指针curr.保证curr左边全部是有序排序，curr右边全部都是未排序的
    //所以我们当curr指针遇到2时，和right交换，同时right--，此时不能保证交换过来的值一定是正确值，所以curr不动
    //当curr指针遇到0时，和left交换，同时left++，此时交换过来的要么是1，可以直接++，要么是0，直接有序，也可以直接++，所以
    //curr遇到0的时候curr不用动。
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len==1)
            return;
        int i=0;
        int left = 0,right = len-1;
        while(i<=right)
        {
            if(nums[i]==0)
            {
                swap(nums,i,left);
                left++;
                i++;
                
            }
            else if(nums[i]==2)
            {
                swap(nums,i,right);
                right--;
                
            }
            else
                i++;
        }
    }
    void sortColors1(vector<int>& nums) {
        //方法二：笨办法，统计0，1，2的个数，直接改写
        int len = nums.size();
        int count0=0,count1=0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]==0)
                count0++;
            if(nums[i]==1)
                count1++;
        }
        int count2 = len-count0-count1;
        for(int i=0;i<len;i++)
        {
            if(i<count0)
                nums[i] = 0;
            if(i>=count0||i<count1)
                nums[i] = 1;
            else
                nums[i] = 2;
        }
    }

};
