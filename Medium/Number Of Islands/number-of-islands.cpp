//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Disjoint_set{
    public:
    vector<int>rank,parent;
    Disjoint_set(int size)
    {
        rank.resize(size+1,0);
        parent.resize(size+1);
        for(int i=0;i<=size;i++)
        {
            parent[i]=i;
        }
    }
    int findParent(int u)
    {
        if(u==parent[u])
        {
            return u;
        }
        return parent[u]=findParent(parent[u]);
    }
    void unionSet(int u,int v)
    {
        int ulp_u=findParent(u);
        int ulp_v=findParent(v);
        if(ulp_u==ulp_v)
        {
            return;
        }
        if(rank[ulp_u]>rank[ulp_v])
        {
            parent[ulp_v]=ulp_u;
        }
        else if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        Disjoint_set ds(n*m);
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<int>ans;
        int cnt=0;
        for(auto it:operators)
        {
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt+=1;
            int delRow[4]={-1,0,1,0};
            int delCol[4]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int newr=row+delRow[i];
                int newc=col+delCol[i];
                if(newr>=0 && newc>=0 && newr<n && newc<m)
                {
                    if(vis[newr][newc]==1){
                    int u=(row*m)+col;
                    int v=(newr*m)+newc;
                    if(ds.findParent(u)!=ds.findParent(v))
                    {
                        cnt--;
                        ds.unionSet(u,v);
                    }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends