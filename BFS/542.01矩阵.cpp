/*

Category	Difficulty	Likes	Dislikes
algorithms	Medium (37.21%)	133	-
Tags
Companies
google

给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1: 
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2: 
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。
*/

// @lc code=start
class Solution {
public:
    int dx[4] = {0,1,-1,0};
    int dy[4] = {1,0,0,-1};
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    //方法一：自己的方法，就是找到每一个1然后bfs去找离他最近的0，有一个case会超时
    int cal_distance(vector<vector<int>>& matrix,int i,int j,int row,int col)
    {
        //bfs计算matrix[i][j]中离0的最近距离
        queue<pair<int,int>>q;
        vector<vector<int>> visit(row,vector<int>(col,0));
        q.push(make_pair(i,j));
        visit[i][j] = 1;
        int distance = 0;
        while(!q.empty())
        {
            //distance++;
            pair <int,int>tmp = q.front();
            q.pop();
            for(int k=0;k<4;k++)
            {
                int x = tmp.first+dx[k];
                int y = tmp.second+dy[k];
                if(x>=0&&x<row&&y>=0&&y<col&&visit[x][y]==0)
                {
                    visit[x][y] = 1;
                    if(matrix[x][y]==0)
                    {
                        int distance = abs(x-i)+abs(y-j);
                        return distance;
                    }
                    else
                    {
                        q.push(pair<int,int>(x,y));
                    }
                }
            }
        }
        return distance;
    }
    vector<vector<int>> updateMatrix1(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> ans(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==0)
                {
                    ans[i][j] = 0;
                }
                else
                {
                    int d = cal_distance(matrix,i,j,row,col);
                    ans[i][j] = d;
                }   
            }
        }
        return ans;
        
    }
    //方法二：先把0都放到队列里，然后根据0进行扩散
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> q;
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }
        // 广度优先搜索
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;//距离等于0加1
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }
    return dist;
    }
};
