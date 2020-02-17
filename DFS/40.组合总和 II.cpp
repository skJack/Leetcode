/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (59.28%)	202	-
Tags
Companies
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
*/

// @lc code=start
class Solution {
public:
    //这里用了三个去重复的方法
    //used数组用于去掉本身的重复，不然就会出一个数字可以用无数次
    //index用于不去遍历之前的数字，因为之前的数字已经被遍历过，不走回头路
    //第33行那里是处理数组中本身有重复数字的情况，和47问题一样
    void dfs(vector<int>& candidates, int target,int len,int index,vector<int>&path,vector<bool>&used,vector<vector<int>>&ans)
    {
        //这里used是去除本身，index是去除以前的重复
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
        for(int i=index;i<len;i++)
        {   
            //去掉重复    
            if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==false||(candidates[i]>target))
                continue;
            if(used[i]==false)
            {
                //没被用过
                used[i]=true;
                path.push_back(candidates[i]);
                dfs(candidates,target,len,i,path,used,ans);
                used[i] = false;
                path.pop_back();//回溯
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        
        vector<vector<int>>ans;
        if(len==0)
            return ans;
        sort(candidates.begin(),candidates.end());
        vector<int>path;
        vector<bool>used(len,false);
        dfs(candidates,target,len,0,path,used,ans);
        return ans;

    }
};
