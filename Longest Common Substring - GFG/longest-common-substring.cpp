//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
int longestCommonSubstr(string S1, string S2, int n, int m) {
    int s1 = S1.size();
    int s2 = S2.size();
    vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
  
    int ans = 0;
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            if(S1[i-1]==S2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
                ans =max(dp[i][j],ans);
            }
            
        }
    }
    return ans;
}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends