/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (59.12%)	127	-
Tags
Companies
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：

给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
说明:

你可以假设数组不可变。
会多次调用 sumRange 方法。
*/
// @lc code=start
class NumArray {
public:
    /*
    //方法一：dp打表，但是内存会超
    vector<int> data;
    vector<vector<int>>res;

    NumArray(vector<int>& nums) {
        //构造函数
        int len = nums.size();
        data = nums;
        vector<vector<int>>dp(len+1,vector<int>(len+1,0));
        cout<<dp.size()<<" "<<dp[0].size();
        for(int i=1;i<=len;i++)
        {
            for(int j=i;j<=len;j++)
            {
                dp[i][j]=dp[i][j-1]+nums[j-1];//注意dp是从1开始索引
            }
        }
        res = dp;
    }
    int sumRange(int i, int j) {
        return res[i+1][j+1];
    }*/
    //方法二：上面那个空间会超，压缩空间很简单，但是居然没想到，就是用减法，dp只存储0~i的和，之后用减法就好
    vector<int>res;
    NumArray(vector<int>& nums){
        int len = nums.size();
        vector<int>dp(len+1,0);
        for(int i=1;i<=len;i++)
        {
            dp[i] = dp[i-1]+nums[i-1];
        }
        res = dp;
    }
    int sumRange(int i,int j)
    {
        return res[j+1]-res[i];
    }
};
