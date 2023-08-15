//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool fs(vector<vector<int>>& dp, int sum, int n, vector<int>& arr) {
    if (sum == 0) return 1;
    if (n < 0 || sum < 0) return 0;
    if (dp[n][sum]!=-1) return dp[n][sum];
    
    if (arr[n] <= sum) {
        dp[n][sum] = fs(dp, sum - arr[n], n - 1, arr) || fs(dp, sum, n - 1, arr);
    } else {
        dp[n][sum] = fs(dp, sum, n - 1, arr);
    }

    return dp[n][sum];
}

bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(sum + 1,-1));
    fs(dp, sum, n - 1, arr);
    // print2d(dp,n,sum+1);
    return dp[n-1][sum];
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