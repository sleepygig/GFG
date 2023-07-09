//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
         #define lli long long
        int sum=0;
        int d=abs(target); 
        int n=A.size();
      for(lli i=0;i<n;i++)
    {
        sum+=A[i];    
    }
      if((d+sum)%2 != 0) return 0;
      sum=(d+sum)/2;
    vector<vector<lli>>dp(n+1,vector<lli> (sum+1,0));
    for(lli i=0;i<=n;i++)
    {
       for(lli j=0;j<=sum;j++)
       {
           
            if(i==0)
            {
                dp[i][j]=0;
            }
       }
    }
    dp[0][0]=1;
        for(lli i=1;i<=n;i++)
        {
       for(lli j=0;j<=sum;j++)
       {
            if(A[i-1]<=j)
            {
                dp[i][j]=(dp[i-1][j-A[i-1]]+dp[i-1][j]);
            }
            else 
            {
                dp[i][j]=dp[i-1][j];
            }
       }
    }
    // print2d(dp,n,sum);

   return dp[n][sum];       
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends