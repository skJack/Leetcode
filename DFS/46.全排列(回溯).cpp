/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (73.58%)	525	-
Tags
Companies
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

// @lc code=start
class Solution {
public:
    void dfs(vector<int>& nums,int len,int depth,vector<int>&path,vector<bool>&used,vector<vector<int>> &res)
    {
        if(depth==len)
        {
            //当树的深度为数组长度的时候，就该返回并且存储
            res.push_back(path);
            return;
        }
        else
        {
            for(int i=0;i<len;i++)
            {
                if(used[i]==false)
                {
                    //这个还没有访问过
                    path.push_back(nums[i]);
                    used[i] = true;
                    dfs(nums,len,depth+1,path,used,res);//根据一支进行dfs
                    //回溯，为了不让上面的结果影响同深度的树的生成，必须对path变量和used变量进行回溯
                    used[i] = false;
                    path.pop_back();
                }
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> res;
        if(len==0)
            return res;
        vector<bool>used(len,false);
        vector<int>path;
        dfs(nums,len,0,path,used,res);
        return res;
    }
};
