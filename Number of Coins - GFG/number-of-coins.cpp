//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
int fs(vector<vector<int>>&dp,int M,int V,int coins[])
{
    if(V==0) return 0;
    if(V!=0 and M==0) return 50000;
    if(V<0) return 50000;
    if(dp[M][V]!=-1) return dp[M][V];
    if(coins[M-1]<=V)
    {
        dp[M][V]=min(1+fs(dp,M,V-coins[M-1],coins),fs(dp,M-1,V,coins));
    }
    else
    {
        dp[M][V]=fs(dp,M-1,V,coins);
    }  
    return dp[M][V]; 
    
}
 int minCoins(int coins[], int M, int V) 
	{ 

	    vector<vector<int>>dp(M+1,vector<int>(V+1,-1));
        int x= fs(dp,M,V,coins);
        if(x==50000) return -1;
        return x;

	}
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends