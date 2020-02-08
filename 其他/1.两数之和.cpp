/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (45.82%)	5016	-
Tags
Companies
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
//用哈希表先保存每个数字的位置那之后将加法转化成减法判断哈希表即可
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a(2);
        int size = nums.size();
        map<int,int>hash;
        for(int i =0;i<size;i++)
        {
            hash[nums[i]] = i;
        }
        for(int i=0;i<size;i++)
        {
            map<int,int>::iterator it;
            it = hash.find(target-nums[i]);
            if(it!=hash.end())
            {
                if(it->second !=i)
                {
                    a[0]=it->second;
                    a[1]=i;
                    return a;
                }
            }
        }
        return a;
    }
};
