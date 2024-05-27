//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fn(vector<int>&height,vector<int>&dp,int n,int k)
    {
        if(n==0)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int steps=1e9;
        for(int i=1;i<=k;i++)
        {
            int jump=1e9;
            if(n-i>=0)
            {
                jump=fn(height,dp,n-i,k)+abs(height[n]-height[n-i]);
            }
            steps=min(jump,steps);
        }
        return dp[n]=steps;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n,-1);
        return fn(height,dp,n-1,k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends