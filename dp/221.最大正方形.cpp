/*
最大正方形
Category	Difficulty	Likes	Dislikes
algorithms	Medium (38.84%)	216	-
Tags
Companies
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4
/*

动态规划问题。设二维数组dp[m][n]，其中dp[i][j]表示以坐标(i,j)为右下角元素的最大正方形的边长。

通过观察我们可以看出当前位置的最大正方形边长为上，左，左上三个位置最大正方形边长的最小值+1。（必须这三个正方形同时满足&&该位置matrix[i][j]==1 的条件下，最大边长）

得到动态规划方程：
如果 matrix[i][j] == 1
dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
否则
dp[i][j]=0

*/
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //if (matrix == NULL || matrix.size() < 1 || matrix[0].size() < 1) return 0;
        int row = matrix.size();
        if(row==0)  return 0;
        int col = matrix[0].size();
        if(row==0||col==0)
            return 0;
        //cout<<row<<" "<<col;
        int dp[row+1][col+1] = {0};//为了对齐，让dp数组索引从1开始
        int maxlen=0;
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j] = min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                    if(maxlen<dp[i][j])
                        maxlen = dp[i][j];
                }
            }
        }
        return maxlen*maxlen;
    }
    //这个题如何定义dp很重要
    //d[i][j]表示坐标点i,j为右下角的最大正方形
    //如果说你的 d[i,j] 是想 这个区域中 最大的正方形，那可就麻烦太多了。
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int >> dp(rows, vector<int>(cols,0));     // dp[i][j]表示以坐标i,j作为右下角的最大矩形边长
        int maxLen = 0;
        // 初始化第一列
        for (int i = 0; i < rows; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            maxLen = max(maxLen,dp[i][0]);
        }
        // 初始化第一行
        for (int j = 0; j < cols; ++j) {
            dp[0][j] = matrix[0][j] - '0';
            maxLen = max(maxLen,dp[0][j]);
        }//需要初始化
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j]=='0') continue;  // 面积为0
                int len1 = dp[i-1][j];
                int len2 = dp[i][j-1];
                int len3 = dp[i-1][j-1];
                dp[i][j] = min(min(len1,len2),len3) + 1;    // 满足条件的最大边长
                maxLen = max(dp[i][j], maxLen);
            }
        }
        return maxLen*maxLen;
    }

};
