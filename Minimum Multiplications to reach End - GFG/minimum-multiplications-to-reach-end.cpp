//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

   int minimumMultiplications(vector<int>& arr, int start, int end) {
        #define pi pair <int ,int>
        queue<pi>q;
            vector<int>dis(100000,1e9);
            dis[start]=0;
              q.push({dis[start],start});
            while(q.size()>0)
            {
              int tp=q.front().second;
              int steps=q.front().first;
              if(tp==end) return steps;
              q.pop();
              for(int i=0;i<arr.size();i++)
              {
                int adn=(tp*arr[i])%100000;
             
                if(dis[adn]>steps+1)
                {
                  dis[adn]=steps+1;
                  q.push({dis[adn],adn});
                 }
              }
            }
       return -1;
    }

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends