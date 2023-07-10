//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
      int fs(int price[], int n,int l, int len[],vector<vector<int>>&dp)
  {
      if(n==0 or l==0 ) return 0;
      if(dp[n][l]!=-1)
      {
        return dp[n][l];
      }
      if(len[n-1]<=l)
      {
          dp[n][l]=max(fs(price,n,l-len[n-1],len,dp)+price[n-1],fs(price,n-1,l,len,dp));
      }
      else 
      {
          dp[n][l]=fs(price,n-1,l,len, dp);
      }
      return dp[n][l];
  }
    int cutRod(int price[], int n) {
        int len[n];
        for(int i=0;i<n;i++)
        {
            len[i]=i+1;
        }
        int l=n;
        vector<vector<int>>dp(n+1,vector<int>(l+1,-1));
        return fs(price,n,l,len,dp);
        // print2d(dp,n,l);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends