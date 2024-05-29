//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int fn(vector<int>&nums,int x,int n,vector<int>&dp)
	{
	    if(x==0)
	    {
	        return 0;
	    }
	    if(dp[x]!=-2)
	    {
	        return dp[x];
	    }
	    int min_coins=1e9;
	    for(int i=0;i<n;i++)
	    {
	        int coin=1e9;
	        if(x-nums[i]>=0)
	        {
	           coin=1+fn(nums,x-nums[i],n,dp);
	        }
	        min_coins=min(min_coins,coin);
	    }
	    return dp[x]=min_coins;
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    // Code here
	    int n=nums.size();
	    vector<int>dp(amount+1,-2);
	    int min_coins=fn(nums,amount,n,dp);
	    if(min_coins==1e9)
	    {
	        return -1;
	    }
	    return min_coins;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends