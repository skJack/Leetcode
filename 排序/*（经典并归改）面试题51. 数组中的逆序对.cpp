/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

 

示例 1:

输入: [7,5,6,4]
输出: 5
 

限制：

0 <= 数组长度 <= 50000


*/
class Solution {
public: 
    //方法一：暴力超时
    int reversePairs1(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                if(nums[i]>nums[j])
                    ans++;
            }
        }
        return ans;
    }
    //方法二：归并排序法.利用归并排序已经得到的信息进行计算。
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if(len<2)
            return 0;
        vector<int> tmp(len,0);
        return reversepairs(nums,0,len-1,tmp);

    }
    int reversepairs(vector<int>& nums,int left,int right,vector<int>&tmp)
    {
        //返回[left,right]这个区间中的逆序对的个数
        if(left==right)
        {
            //当只有一个元素时，一定没有逆序对
            return 0;
        }
        int mid = left+(right-left)/2;
        int left_pairs = reversepairs(nums,left,mid,tmp);
        int right_pairs = reversepairs(nums,mid+1,right,tmp);
        int cross_pairs = merageAndCount(nums,left,mid,right,tmp);//计算跨越两个有序数组中的逆序对
        return left_pairs+right_pairs+cross_pairs;
    }
    int merageAndCount(vector<int>& nums,int left,int mid,int right,vector<int>&tmp)
    {
        for(int i=left;i<=right;i++)
        {
            //复制子数组
            tmp[i] = nums[i];
        }
        int i = left;
        int j = mid+1;
        int count = 0;
        for(int k = left;k<=right;k++)
        {
            if(i==mid+1)
            {
                //i用完，将j归并回去
                nums[k] = tmp[j];
                j++;
            }
            else if(j==right+1)
            {
            //j用完
                nums[k] = tmp[i];
                i++;
            }

            else if(tmp[i]<=tmp[j])//注意要写等号，不然不稳定
            {
                nums[k] = tmp[i];
                i++;
            }
            else{
                nums[k] = tmp[j];
                j++;
                count+=(mid-i+1);//当右边数组被选上时，所有比当前数大的数字都在左数组中，所以计数器需要加上目前剩余的左数组的个数
            }
        }
        return count;
        

    }

};


