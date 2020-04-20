/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (64.38%)	175	-
Tags
Companies
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

 

示例 :

输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

输出: 16

解释: 它的周长是下面图片中的 16 个黄色的边：

*/

// @lc code=start
class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visit,int i,int j,int row,int col)
    {
        if(i<0||i>row-1||j<0||j>col-1)
        {
            ans++;
            return;
        }
        else if(grid[i][j]==0)
        {
            ans++;
            return;
        }
        else if(visit[i][j]==1)
        {
            return;
        }
        else
        {
            visit[i][j]=1;
            dfs(grid,visit,i+1,j,row,col);
            dfs(grid,visit,i,j+1,row,col);
            dfs(grid,visit,i-1,j,row,col);
            dfs(grid,visit,i,j-1,row,col);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int idx_i,idx_j;
        bool flag = false;
        vector<vector<int>> visit(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++)
        {
            if(flag)
                break;
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    idx_i = i;
                    idx_j = j;
                    flag = true;
                    break;
                }
            }
        }
        dfs(grid,visit,idx_i,idx_j,row,col);
        return ans;
    }
};
