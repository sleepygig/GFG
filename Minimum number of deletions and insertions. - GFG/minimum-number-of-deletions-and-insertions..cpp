//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	 int  fs(string &str1, int s1, string &str2,int s2,vector<vector<int>>&dp)
    {
        if(s1==0 or s2==0) return 0;
        if(dp[s1][s2]!=0) return dp[s1][s2];
        if(str1[s1-1]==str2[s2-1])
        {
            dp[s1][s2]=1+fs(str1,s1-1,str2,s2-1,dp);
        }
        else
        {
            dp[s1][s2]=max(fs(str1,s1-1,str2,s2,dp),fs(str1,s1,str2,s2-1,dp));
        }
        return dp[s1][s2];
    }
	int minOperations(string str1, string str2) 
	{ 
	    int s1=str1.size();
        int s2=str2.size();
        vector<vector<int>>dp(s1+1,vector<int> (s2+1,0));
        fs(str1,s1,str2,s2,dp);
        return (s1+s2-2*fs(str1,s1,str2,s2,dp));
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends