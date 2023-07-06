//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
 bool fs(vector<vector<int>>&dp, int arr[], int n, int sum) {
  if (sum == 0) return true;
  if (n == 0) return false;

  if (dp[n][sum] != -1) return dp[n][sum];
  if (sum >= arr[n - 1]) {
    dp[n][sum] = fs(dp, arr, n - 1, sum - arr[n - 1]) || fs(dp, arr, n - 1, sum);
  } else {
    dp[n][sum] = fs(dp, arr, n - 1, sum);
  }
}

   int equalPartition(int N, int arr[])
    {
      
   long long  sum=0;
      for(int i=0;i<N;i++){sum+=arr[i];}
    if(sum&1) return 0;
      sum=sum/2;
        vector<vector<int>>dp(N+1,vector<int>(sum+1,-1));
        fs(dp,arr,N,sum);
        return dp[N][sum];
       
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends