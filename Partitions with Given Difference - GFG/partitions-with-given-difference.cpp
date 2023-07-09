//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     #define lli long long 
 const int  M=1e9+7;
                //Macros for Modular arthematic
        lli modadd(lli a, lli b) {a = a % M; b = b % M; return (((a + b) % M) + M) % M;}
        lli modmul(lli a, lli b) {a = a % M; b = b % M; return (((a * b) % M) + M) % M;}
        lli modsub(lli a, lli b) {a = a % M; b = b % M; return (((a - b) % M) + M) % M;}
 int countPartitions(int n, int d, vector<int>& arr) {
    #define lli long long 
     lli sum=0;   
     lli m=1e9+7;
    for(lli i=0;i<n;i++)
    {
        sum+=arr[i];    
    }
      if((d+sum)%2 != 0) return 0;
      sum=(d+sum)/2;
    vector<vector<lli>>dp(n+1,vector<lli> (sum+1,0));
    dp[0][0]=1;
        for(lli i=1;i<=n;i++)
        {
       for(lli j=0;j<=sum;j++)
       {
            if(arr[i-1]<=j)
            {
                dp[i][j]=modadd(dp[i-1][j-arr[i-1]],dp[i-1][j]);
            }
            else 
            {
                dp[i][j]=dp[i-1][j]%m;
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
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends