//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
bool dfs(int src, int par, vector<int> adj[], vector<int>& vis) {
    vis[src] = 1;
    for (auto c : adj[src]) {
        if (!vis[c]) {
            vis[c] = 1;
            if (dfs(c, src, adj, vis)) return true;
        } else if (c != par) {  // Changed from "else if (c == par)"
            return true;
        }
    }
    return false;
}

    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        bool y=false;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                y=y or dfs(i,-1,adj,vis);
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