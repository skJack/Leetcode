组合总和
Category	Difficulty	Likes	Dislikes
algorithms	Medium (67.94%)	529	-
Tags
Companies
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

// @lc code=start
//此题和全排列有些像，都是回溯的框架，但是这里要注意一个是终止条件的变化。
//另一个是增加了index，可以筛选出重复的选项。这种题就是画出递归树就可以看出剪枝套路
//每次让i从index开始即可
class Solution {
public:
    void dfs(vector<int>& candidates, int target,int len,int depth,vector<int>&path,vector<vector<int>>&ans,int index)
    {
        int path_len = path.size();
        int sum = 0;
        for(int i=0;i<path_len;i++)
        {
            sum+=path[i];
        }
        if(sum==target)
        {
            ans.push_back(path);
            return;
        }
        if(sum>target)
            return;
        int tmp_sum=0;
        for(int i=index;i<len;i++)
        {
            path.push_back(candidates[i]);
            dfs(candidates,target,len,depth+1,path,ans,i);//注意这里index取i
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int len = candidates.size();
        vector<vector<int>> ans;
        vector<int>path;
        dfs(candidates,target,len,0,path,ans,0);
        return ans;
    }
};
