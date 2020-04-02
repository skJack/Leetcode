/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (67.89%)	155	-
Tags
Companies
根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

 

示例：

输入： 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
输出：
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
 

进阶：

你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
本题中，我们使用二维数组来表示面板。原则上，面板是无限的，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？
*/

// @lc code=start
class Solution {
public:
    //暴力法，看题解还有一种复合状态，比如设定为2.可以再学一遍，但是没有必要。
    //感觉现在自己写这种模拟题越来越快了，这题一遍过，感觉还是有进步的。加油！
    void gameOfLife(vector<vector<int>>& board) {
        //上下左右
        int direct_x[8] = {0,0,1,-1,1,1,-1,-1};
        int dirext_y[8] = {1,-1,0,0,1,-1,1,-1};
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>>ans(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int cell = board[i][j];
                int num_dead = 0;
                int num_live = 0;
                for(int k=0;k<8;k++)
                {
                    int tmp_x = i+direct_x[k];
                    int tmp_y = j+dirext_y[k];
                    if(tmp_x>=0&&tmp_x<row&&tmp_y>=0&&tmp_y<col)
                    {
                        if(board[tmp_x][tmp_y]==0)
                            num_dead++;
                        else
                            num_live++;
                    }
                }
                if(cell==1)
                {
                    if(num_live<2)
                        ans[i][j] = 0;
                    if(num_live==2||num_live==3)
                        ans[i][j] = 1;
                    if(num_live>3)
                        ans[i][j] = 0;
                }
                if(cell==0)
                {
                    if(num_live==3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }
            }
        }
        board = ans;
    }
};
// @lc code=end

