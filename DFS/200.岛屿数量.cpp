/*
岛屿数量
Category	Difficulty	Likes	Dislikes
algorithms	Medium (46.40%)	318	-
Tags
Companies
给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

示例 1:

输入:
11110
11010
11000
00000

输出: 1
示例 2:

输入:
11000
11000
00100
00011

输出: 3
*/
//方法一:dfs
class Solution {
public:
    void helper(int i,int j,int row,int col,vector<vector<char>>& grid,vector<vector<bool>> &visit)
    {
        if(i==-1||i>row-1||j==-1||j>col-1)
        //if(i==-1||j==-1)
        {
            return;
        }
        else if(grid[i][j]=='0'||visit[i][j]==true)
        {
            return;
        }
        else
        {
            visit[i][j] = true;
            helper(i+1,j,row,col,grid,visit);
            helper(i-1,j,row,col,grid,visit);
            helper(i,j+1,row,col,grid,visit);
            helper(i,j-1,row,col,grid,visit);
        }
        
    }
    //方法一：dfs遍历，并每次记录根节点的数量
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row==0)
            return 0;
        int col = grid[0].size();
        vector<vector<bool>>visit(row,vector<bool>(col,false));
        int ans = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1'&&visit[i][j]==false)
                {
                    //发现新大陆
                    ans++;
                    helper(i,j,row,col,grid,visit);
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<visit[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
    //方法二：并查集，todo
};
