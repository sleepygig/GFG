//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
int fs(vector<vector<int>>&dp,int n,int sum,vector<int>&a)
{
    if(n==1)
    {
        if(a[n-1]==0 and sum==0 ) return 2;
        if(sum==0 or a[n-1]==sum) return 1;
        return 0;
    }
        // if (n == 0) {
        // return (sum == 0) ? 1 : 0;
    // }

    if(dp[n][sum]!=-1) return dp[n][sum];
    int take,notake;
    if(a[n-1]<=sum)
    {
        take=fs(dp,n-1,sum-a[n-1],a);
        notake=fs(dp,n-1,sum,a);
    }
    else 
    {
         take=0;
        notake=fs(dp,n-1,sum,a);
    }
    return dp[n][sum]=take+notake;
}


 int findTargetSumWays(vector<int>&A ,int target) {
        int sum=accumulate(A.begin(),A.end(),0);
        int n=A.size();
        // deb(sum);
          if((sum+target)%2==1) return 0;
         int s2=(sum+target)/2;
        vector<vector<int>>dp(n+1,vector<int>(s2+1,-1));
         return fs(dp,n,s2,A);
        //  print2d(dp,n+1,s2+1);
        //  deb(dp[n][s2]);

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