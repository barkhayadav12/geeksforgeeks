//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<long long,long long>>adj[n];
        for(auto it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,1e18);
        dist[0]=0;
        vector<long long>ways(n,0);
        ways[0]=1;
        int mod=(int)(1e9+7);
        while(!pq.empty())
        {
            long long dis=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                long long wt=it.second;
                long long adjNode=it.first;
                if(dist[adjNode]>wt+dis)
                {
                    dist[adjNode]=wt+dis;
                    pq.push({wt+dis,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dist[adjNode]==wt+dis)
                {
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends