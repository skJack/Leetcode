/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (56.55%)	219	-
Tags
Companies
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/

// @lc code=start
class Solution {
public:
//思路：首先打框架上和46题一样，之后需要进行剪枝，我们发现只要与当前起点一样就做剪枝，所以就想到先排序
//再去除重复的，注意判断要加上used数组，因为其实第一个出现的不用剪枝，当重复出现时才需要剪枝
//推荐题解：https://leetcode-cn.com/problems/permutations-ii/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liwe-2/
    void dfs(vector<int>& nums,int len,int depth,vector<bool>&used,vector<int>&path,vector<vector<int>> &ans)
    {
        if(depth==len)
        {
            ans.push_back(path);
            return;
        }
        else
        {
            for(int i=0;i<len;i++)
            {
                if(used[i]==false)
                {
                    if(i>0&&nums[i-1]==nums[i]&&used[i-1]==false)//重复
                        continue;
                    else
                    {
                        used[i] = true;
                        path.push_back(nums[i]);
                        dfs(nums,len,depth+1,used,path,ans);
                        used[i] = false;
                        path.pop_back();
                    }
                    
                }
            }
        }
        
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> ans;
        if(len==0)
            return ans;
        sort(nums.begin(),nums.end());
        vector<int> path;
        vector<bool> used(len,false);
        dfs(nums,len,0,used,path,ans);
        return ans;
    }
};
