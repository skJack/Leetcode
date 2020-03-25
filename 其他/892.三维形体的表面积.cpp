/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (55.45%)	90	-
Tags
Companies
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。

请你返回最终形体的表面积。

 

示例 1：

输入：[[2]]
输出：10
示例 2：

输入：[[1,2],[3,4]]
输出：34
示例 3：

输入：[[1,0],[0,2]]
输出：16
示例 4：

输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：32
示例 5：

输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：46
*/

// @lc code=start
//第一次遇到画图问题
//思路：每一块每一块看，有点像dp的思路
//当前表面积等于他自身的表面积减去堆叠形成的。
//有三种堆叠。第一种是竖直堆叠，这个最好算，因为不依赖于别的格子，就是area = tmp*4+2
//之后就是行水平堆叠和列水平堆叠。我们发现只要减去与相邻的格子堆叠数*2即可,而堆叠个数可以就是两者块子的最小值
//所以有ans-=min(tmp,nexttmp)*2
//这里要注意一个很巧妙的点就是仅仅判断相邻就行，我一开始想着要判断四邻域很麻烦，但是其实
//运用dp的思路，只需减去当前块和其前一个相邻块的堆叠部分，至于后面的堆叠部分由下一个块负责减去
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                int tmp = grid[i][j];
                if(tmp>0)
                {
                    ans+=tmp*4+2;
                    if(i>0)
                    {
                        int row_overlap = min(tmp,grid[i-1][j]);
                        ans -= row_overlap*2;
                    }
                    if(j>0)
                    {
                        int col_overlap = min(tmp,grid[i][j-1]);
                        ans -= col_overlap*2;
                    }
                }
            }
        }
        return ans;
    }
};
