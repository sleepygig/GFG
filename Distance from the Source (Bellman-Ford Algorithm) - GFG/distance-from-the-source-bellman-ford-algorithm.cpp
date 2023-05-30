//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        //edges {{u,v,weight}}
        vector<int>dis(V,1e8);
        dis[S]=0;
        for(int i=0;i<V-1;i++)
        {
          for(auto c:edges)
          {
          int u=c[0];
          int v=c[1];
          int wght=c[2];
          if(dis[u]!=1e8 and dis[v]>dis[u]+wght)
          {
            dis[v]=dis[u]+wght;
          }
        }
        }
        for(auto c:edges)
          {
          int u=c[0];
          int v=c[1];
          int wght=c[2];
          if(dis[u]!=1e8 and dis[v]>dis[u]+wght)
          {
            return {-1};
          }
        }
        return dis;
  }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends