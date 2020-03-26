/*

Category	Difficulty	Likes	Dislikes
algorithms	Easy (65.30%)	55	-
Tags
Companies
在一个 8 x 8 的棋盘上，有一个白色车（rook）。也可能有空方块，白色的象（bishop）和黑色的卒（pawn）。它们分别以字符 “R”，“.”，“B” 和 “p” 给出。大写字符表示白棋，小写字符表示黑棋。

车按国际象棋中的规则移动：它选择四个基本方向中的一个（北，东，西和南），然后朝那个方向移动，直到它选择停止、到达棋盘的边缘或移动到同一方格来捕获该方格上颜色相反的卒。另外，车不能与其他友方（白色）象进入同一个方格。

返回车能够在一次移动中捕获到的卒的数量。
*/

// @lc code=start
class Solution {
public:
    int numRookCaptures1(vector<vector<char>>& board) {
        int row = 8;
        int col = 8;
        int ans = 0;
        int ri,rj;
        bool flag = false;
        //找车位
        for(int i=0;i<row;i++)
        {
            if(flag==true)
                break;//找到车的位置
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='R')
                {
                    ri = i;
                    rj = j;
                    flag = true;
                    break;
                }
            }
        }
        //往上走
        int i=ri;
        while(i>=0&&board[i][rj]!='B')
        {
            if(board[i][rj]=='p')
                {
                    ans++;
                    break;
                }
            i--;
        }
        //往下走
        i=ri;
        while(i<8&&board[i][rj]!='B')
        {
            if(board[i][rj]=='p')
                {
                    ans++;
                    break;
                }
            i++;
        }
        //往左走
        int j=rj;
        while(j>=0&&board[ri][j]!='B')
        {
            if(board[ri][j]=='p')
                {
                    ans++;
                    break;
                }
            j--;
        }
        //往右走
        j=rj;
        while(j<8&&board[ri][j]!='B')
        {
            if(board[ri][j]=='p')
                {
                    ans++;
                    break;
                }
            j++;
        }
        return ans;
    }
    //方法二：简写 用增量的方法写成一个循环即可
    int numRookCaptures(vector<vector<char>>& board) {
        int row = 8;
        int col = 8;
        int ans = 0;
        int ri,rj;
        bool flag = false;
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1}; 
        //找车位
        for(int i=0;i<row;i++)
        {
            if(flag==true)
                break;//找到车的位置
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='R')
                {
                    ri = i;
                    rj = j;
                    flag = true;
                    break;
                }
            }
        }
        //学会这种写法
        for(int i=0;i<4;i++)
        {
            int tx = ri+dx[i];
            int ty = rj+dy[i];
            while(tx>=0&&tx<8&&ty>=0&&ty<8)
            {
                if(board[tx][ty]!='.')
                {
                    if(board[tx][ty]=='p')
                        ans++;
                    break;
                }
                tx += dx[i];
                ty += dy[i];
            }
        }
        return ans;
    }
};
