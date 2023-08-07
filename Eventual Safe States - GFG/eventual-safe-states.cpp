//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 bool dfs(vector<int>&path,vector<int>&vis,vector<int> adj[],int src)
  {
      path[src]=1;
      vis[src]=1;
      for(auto c:adj[src])
      {
          if(!vis[c])
          {
              if(dfs(path,vis,adj,c)) return true;
          }
          else if(path[c])
          {
              return true;
          }
      }
      path[src]=0;
      return false;
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>path(V,0);
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i]) dfs(path,vis,adj,i);
        }
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if(!path[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends