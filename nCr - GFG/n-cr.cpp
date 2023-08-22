//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
const int M=1e9+7;
        
      
      int fs(vector<vector<int>>&dp,int n,int r)
      {
        if(n==0 or r==0 or n==r) return 1;
        if(dp[n][r]!=-1) return dp[n][r];
         dp[n][r]=(fs(dp,n-1,r-1)+fs(dp,n-1,r))%M;
         return dp[n][r];
      }
    int nCr(int n, int r){
     vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
     if(r>n) return 0;
     return fs(dp,n,r);
    }


};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends