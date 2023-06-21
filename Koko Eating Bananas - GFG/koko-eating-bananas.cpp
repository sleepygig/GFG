//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int timetocomp(vector<int>& piles,int mid )
{
  int n=piles.size();
  int tot=0;
  for(int i=0;i<n;i++)
  {
     tot += (piles[i] + mid - 1) / mid; 
  }
  return tot;
}
    int Solve(int N, vector<int>& piles, int H) {
        int h=H;
       int lo=1;
        int hi =1e9;
        int mid;
        while(hi-lo>1)
        {
          mid=(lo+hi)>>1;
          if(timetocomp(piles,mid)>h)
          {
            lo=mid+1;
          }
          else
          {
            hi=mid;
          }
     
        }
        
       int ans=(timetocomp(piles,lo)<=h)? lo :hi;

       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends