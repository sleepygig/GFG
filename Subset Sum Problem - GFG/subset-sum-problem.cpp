//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
    int n=arr.size();
       vector<vector<int>>dp(n,vector<int>(sum+1,0));   //dp [i][j] j sum with i numbers ie i-1 th index tk
        for(int j=0;j<n;j++)
            {
              dp[j][0]=1;    //sum==0 is always present empty set  
            }
            if(arr[0]<=sum) dp[0][arr[0]]=1;   //sirf ek term hai 
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<=sum;j++)
                {
                    if(arr[i]<=sum)
                    {

                        dp[i][j]=dp[i-1][j-arr[i]] || dp[i-1][j];
                    }

                    else 
                    {
                        dp[i][j]=dp[i-1][j];
                    }    
                }
            }


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