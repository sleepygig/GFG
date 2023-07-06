//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   bool fs(vector<vector<int >>&dp,int n,vector<int>&arr,int sum)
{
  if(sum==0) return true;
  if(n==0) return false;
  if(sum<0) return false;
  if(dp[n][sum]!=-1) return dp[n][sum];
  if(sum>=arr[n-1])
  {
    return dp[n][sum]=fs(dp,n-1,arr,sum-arr[n-1])|| fs(dp,n-1,arr,sum);
  }
  else 
  {
    return dp[n][sum]=fs(dp,n-1,arr,sum);
  }
}
 bool isSubsetSum(vector<int>arr, int sum){
  int n=arr.size();
       vector<vector<int >>dp(n+1,vector<int >(sum+1,-1));
       return fs(dp,n,arr,sum);
    //   print2d(dp,n,sum);


    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends