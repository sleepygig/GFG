//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int fs (int n, int w, int profit[], int weight[],vector<vector<int>>&dp)
    {
        if(n==0 or w==0) return 0;
        if(dp[n][w]!=-1) return dp[n][w];
        if(w>=weight[n-1])
        {
            dp[n][w]=max(fs(n,w-weight[n-1],profit,weight,dp)+profit[n-1], fs(n-1,w,profit,weight,dp));
        }
        else 
        {
            dp[n][w]=fs(n-1,w,profit,weight,dp);
        }
        return dp[n][w];

    }
    int knapSack(int N, int W, int val[], int wt[])
    {
         vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
    return fs(N,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends