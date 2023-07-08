//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	 
        int sum=accumulate(arr,arr+n,0);
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
       
            for(int i=0;i<n+1;i++)
            {
                for(int j=0;j<sum+1;j++)
                {
                   if(j==0)
                   {
                    dp[i][j]=1;
                   }   
                }
            }
        //i is no of terms 
        //j is till now sum involved 
        
            for(int i=1;i<n+1;i++)
            {
                for(int j=1;j<sum+1;j++)
                {
                    if(j>=arr[i-1])
                    {
                        dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                    }
                    else 
                    {
                        dp[i][j]=dp[i-1][j];
                    } 
                }
            }
        // print2d(dp,n,sum);
        int y=INT_MAX;
            for(int i=0;i<=(sum/2);i++)
            {
               if(dp[n][i])
               {
                y=min(y,sum-2*i);
               }
            }
            // deb(y);
           return y;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends