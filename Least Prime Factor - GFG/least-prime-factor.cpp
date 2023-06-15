//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> leastPrimeFactor(int n) {
        
       vector<int>pf(n+1,0);
       pf[1]=1;
      //  pf[2]=2;
       for(int i=2;i<=n;i++)
       {
          if(pf[i]==0)
          {    pf[i]=i;                   //agr kisika prime factor
            for(int j=i*i;j<=n;j+=i)
            {
                if(pf[j]==0)pf[j]=i;
            }
          }
       }
       return pf;
      //  for(int i=0;i<=n;i++)
      //  {
      //     cout<<i<<" "<<pf[i]<<endl;
      //  }
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends