//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {   swap(m,n);
           vector<vector<int>>dp(m+1,vector<int> (n+1,0));
       for(int i=1;i<=m;i++)
       {
          for(int j=1;j<=n;j++)
          {
              if(s1[i-1]==s2[j-1])
              {
                  dp[i][j]=dp[i-1][j-1]+1;
              }
              else 
              {
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
          }
       }
       return dp[m][n];
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends