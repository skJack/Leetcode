/*
岛屿的最大面积
Category	Difficulty	Likes	Dislikes
algorithms	Medium (59.10%)	216	-
Tags
array | depth-first-search

Companies
给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。

示例 2:

[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。
*/

// @lc code=start
class Solution {
public:
    //思路：dfs，加一个count判断就行了
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visit,int &count,int row,int col,int x,int y)
    {
        if(x<0||x>row-1||y<0||y>col-1)
        {
            return;
        }
        if(grid[x][y]==0||visit[x][y]==true)
        {
            return;
        }
        else
        {
            visit[x][y] = true;
            count++;
            dfs(grid,visit,count,row,col,x,y+1);
            dfs(grid,visit,count,row,col,x,y-1);
            dfs(grid,visit,count,row,col,x+1,y);
            dfs(grid,visit,count,row,col,x-1,y);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int ans=0;
        int count = 0;
        if(row==0)
            return 0;
        int col = grid[0].size();
        vector<vector<bool>>visit(row,vector<bool>(col,false));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1||visit[i][j]==false)
                {
                    dfs(grid,visit,count,row,col,i,j);
                    ans = max(ans,count);
                    count = 0;
                }
            }
        }
        return ans;
    }
};
