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
    int l=mine(dp,n-1,height);
    int r=mine(dp,n-2,height);
    int o1=INT16_MAX;
    int o2=INT16_MAX;
     o1=l+abs(height[n]-height[n-1]);
     if(n>1)o2=r+abs(height[n]-height[n-2]);
     return dp[n]=min(o1,o2);
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