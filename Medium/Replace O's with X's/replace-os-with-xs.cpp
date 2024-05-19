//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    private:
    void dfs(vector<vector<char>>&mat,vector<vector<int>>&vis,int row,int col)
{
    vis[row][col]=1;
    int n=mat.size();
    int m=mat[0].size();
    int delRow[4]={-1,0,1,0};
    int delCol[4]={0,1,0,-1};
    for(int i=0;i<4;i++)
    {
        int nrow=row+delRow[i];
        int ncol=col+delCol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]=='O' && !vis[nrow][ncol])
        {
            dfs(mat,vis,nrow,ncol);
        }
    }
}

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 || j==0 || i==n-1 || j==m-1)
            {
                if(mat[i][j]=='O' && !vis[i][j])
                {
                    dfs(mat,vis,i,j);
                }
            }
        }
    }
    vector<vector<char>>ans(n,vector<char>(m,'X'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(vis[i][j] && mat[i][j]=='O')
            {
                ans[i][j]='O';
            }
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends