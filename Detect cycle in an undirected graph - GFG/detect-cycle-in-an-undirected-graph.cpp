//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
  bool dfs(vector<int> adj[],vector<bool>&vis,int &src,int parent )
{
    vis[src]=1;
    for(auto c:adj[src])
    {
      
        if(!vis[c])
        {
            if(dfs(adj,vis,c,src)) return true;
        }
        else if(c!=parent) return true;
    }
    return false;
}
   bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V,0);
        bool y=false;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                y=y or dfs(adj,vis,i,-1);
            }
        }
        return y;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends