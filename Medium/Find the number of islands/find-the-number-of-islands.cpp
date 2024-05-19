//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int row,int col)
{
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    int delRow[8]={ -1, -1, -1, 0, 0, 1, 1, 1 };
    int delCol[8]= { -1, 0, 1, -1, 1, -1, 0, 1 };
    for(int i=0;i<8;i++)
    {
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol])
        {
            dfs(grid,vis,nrow,ncol);
        }
    }
}
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1' && !vis[i][j])
            {
                cnt++;
                dfs(grid,vis,i,j);
            }
        }
    }return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends