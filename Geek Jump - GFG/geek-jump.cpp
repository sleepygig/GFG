//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
int mine(map<int,int>&dp,int n,vector<int>& height)
{
    if(n<=0) return 0;
    if(dp[n]) return dp[n];
    int l,r;
       l=mine(dp,n-1,height) +abs(height[n-1]-height[n]);
     if(n>1) {r=mine(dp,n-2,height)+abs(height[n-2]-height[n]);}
    else {r=INT_MAX;}
    return dp[n]=min(l,r);
}

int minimumEnergy(vector<int>& height, int n) {
    map<int, int> dp;

    
    mine(dp, n, height);
    return dp[n - 1];
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends