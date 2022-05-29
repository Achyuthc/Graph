


/*You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:

0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).*/


class Solution {
public:
    
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int m,n;
   
    
    int minimumObstacles(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>> dist(m+1, vector<int>(n+1, 1e9));
        deque<pair<int,int>> q;
        q.push_back({0,0});
        dist[0][0]=0;
        
        int dx,dy;
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop_front();
               
                if(x==m-1&&y==n-1)
                    return dist[x][y];
                for(int j=0;j<4;j++)
                {
                    dx=x+dir[j][0],dy=y+dir[j][1];
                    if(dx>=0&&dx<m&&dy>=0&&dy<n&&dist[dx][dy]>dist[x][y]+grid[dx][dy])
                    {
                        dist[dx][dy]=dist[x][y]+grid[dx][dy];
                        if(grid[dx][dy])
                        {
                            q.push_back({dx,dy});
                        }
                        else
                        {
                            q.push_front({dx,dy});
                        }
                      
                    }
                }
                
            }
        
        return dist[m-1][n-1];
        
    }
};
